#include<iostream>

using namespace std;

template<typename T>

void InsertionSort(T* arr, int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i;
        while(j>0 && arr[j-1] > temp){
            arr[j] = arr[j-1];
            j--;
        }

        arr[j] = temp;
    }
}

template<typename T>

void InsertionSortRecursive(T* arr, int n){
    for(int i=)
}

int main(){
    int arr[] = {5,3,6,26,2,24};
    int n = sizeof(arr)/sizeof(int);

    InsertionSort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//The time complxity of the insertion sort is also O(n^2)
