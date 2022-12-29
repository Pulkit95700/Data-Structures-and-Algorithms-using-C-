#include<iostream>

using namespace std;

void InsertionSort(int arr[], int n, int gap){
    
    for(int i=gap; i<n; i++){
        int j = i-gap;
        int temp = arr[i];

        while(j >= 0 && arr[j] > temp){
            arr[j + gap] = arr[j];
            j-=gap;
        }
        
        arr[j+gap] = temp;
    }
}
void ShellSort(int arr[], int n){
    int gap = n/2;

    while(gap >= 1){
        InsertionSort(arr,n, gap);
        gap = gap/2;
    }    
}
int main(){

    int arr[] = {4,3,53,2,3,10,1,6};
    int n = sizeof(arr)/sizeof(int);
    ShellSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}