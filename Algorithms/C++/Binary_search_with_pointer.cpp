#include <iostream>
using namespace std;
//bin
int * binary_search(int arr[], int item, int size) {
    int low = 0;
    int high = size - 1;
    int mid = 0;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == item){ return arr+mid; }
        if(arr[mid] < item){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return 0;
}

int iter(int num){
    int i;
    for(; num != 1; (++num) /= 2, ++i){
        cout << num<<  ' ';
    }
    cout  << endl;
    return i;
}

int main() {

    int arr[5] = {1,2,3, 7, 8};
    cout << binary_search(arr, 3, (sizeof(arr))/(sizeof(int)));
    cout <<endl<< iter(128);
}
