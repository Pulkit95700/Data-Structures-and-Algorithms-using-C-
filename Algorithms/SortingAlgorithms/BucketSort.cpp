#include<iostream>

using namespace std;

int main(){
    int arr[] = {7,3,9,9,10,3};
    int n = sizeof(arr)/sizeof(int);

    WaveSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}