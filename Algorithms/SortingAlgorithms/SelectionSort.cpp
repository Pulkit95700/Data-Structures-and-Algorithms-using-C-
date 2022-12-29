#include<iostream>

using namespace std;

template<typename T>

void SelectionSort(T* arr, T n){
    for(int i=0; i<n-1; i++){
        int k = i;
        for(int j=i; j<n; j++){
            if(arr[j] < arr[k]){
                k = j;
            }
        }
        swap(arr[i], arr[k]);
    }
}
int main(){

    int arr[] = {5,4,3,2,1};
    int n = sizeof(arr)/sizeof(n);
    SelectionSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}