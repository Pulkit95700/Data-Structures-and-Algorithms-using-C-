// In this we compare two adjacent elements. Due to this the largest element goes at the last.

#include<iostream>

using namespace std;
template<typename T>

void BubbleSort(T* arr, int n){
    for(int i=0;i<n;i++){
        bool flag = 0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                if(flag == 0){
                    break;
                }
            }
        }
    }
}

template<typename T>
void BubbleSortRecursive(T* arr, int n){
    if(n>1){
        for(int i=0;i<n-1;i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
        BubbleSortRecursive(arr, n-1);
    }
}

void Bubble_Sort(int A[], int n){
    for(int i=0; i<n; i++){
        bool flag = 0;
        for(int j=0; j< n-i-1;j++){
            if(A[j] > A[j+1]){
                swap(A[j], A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}
int main(){

    int arr[] = {5,3,6,26,2,24};
    int n = sizeof(arr)/sizeof(int);

    Bubble_Sort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//first n-1, then n-2, then n-3
//Time complexity of Algorithm is O(n^2)