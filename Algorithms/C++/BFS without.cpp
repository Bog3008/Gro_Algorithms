#include <iostream>
#include <queue>

using namespace std;
bool is_ok(int a) {
    return a == 6;
}
bool BFS(int ** a, int st, int fin, int size) {
    // queue with 1st line neighbors
    queue <int> q;
    for (int i = 0; i < size; ++i) {
        if (a[st][i] == 1) {
            q.push(i);
        }
    }
    //searched arr
    int* searched = new int[size];
    for (int i = 0; i < size; ++i) { searched[i] = 0; }
    //parents arr
    int* parents = new int[size];
    for (int i = 0; i < size; ++i) { parents[i] = -1; }
    int boof;
    while (!q.empty()) {
        boof = q.front();
        q.pop();
        if(searched[boof] == 0){
            if(boof == fin){
                return true;
            }
            else{
                searched[boof] = 1;
                for (int i = 0; i < size; ++i) {
                    if (a[boof][i] == 1) {
                        q.push(i);
                    }
                }
            }
        }
    }
    delete[] parents;
    delete[] searched;
    return false;
}

int main() {
    queue<int> test;
    test.push(1);
    test.pop();
    int size = 7;
    int ** graph_ = new int* [size];
    for (size_t i = 0; i < size; ++i) {
        graph_[i] = new int[size];
        for (size_t j = 0; j < size; ++j) {
            graph_[i][j] = 0;
        }
    }

    graph_[0][1] = 1;
    graph_[0][2] = 1;
    graph_[1][5] = 1;
    graph_[5][6] = 1;
    graph_[2][4] = 1;
    graph_[2][3] = 1;
    graph_[4][5] = 1;
    graph_[3][5] = 1;
    // BFS

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << graph_[i][j] << " ";
        }
        cout<<endl;
    }
    cout << "BFS:"<<endl;
    cout << BFS(graph_, 0, 6, 7)<<endl;
    cout << "BFSend"<<endl;
    for (size_t i = 0; i < size; ++i) {
        delete graph_[i];
    }
    delete graph_;
}