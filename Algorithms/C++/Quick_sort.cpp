#include <iostream>
using namespace std;

template <class T>
void quick_sort(T * arr, size_t L, size_t R ){
    if(R - L < 2){return;}
    T base = arr[ (R + L) / 2];
    T x = L, y = L;
    for(size_t i = L; i < R; ++i){
        if(arr[i] < base){
            swap(arr[x], arr[i]);
            if(x != y){
                swap(arr[y], arr[i]);
            }
            ++x; ++y;
        }
        else{
            if(arr[i] == base){
                swap(arr[y],arr[i]);
                ++y;
            }
        }
    }
    quick_sort(arr, L, x);
    quick_sort(arr, y, R);
}


int main() {

}
