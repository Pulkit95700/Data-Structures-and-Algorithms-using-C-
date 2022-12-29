#include<iostream>

using namespace std;
//In this algorithm we just make sure that the alternative elments are in the form of wave that is
//arr[0] < arr[1] > arr[2] < arr[3] > arr[4] ........

void WaveSort(int arr[], int n){
    for(int i=1;i<n;i+=2){
        if(arr[i] > arr[i-1]){
            swap(arr[i], arr[i-1]);
        }
        if((arr[i] < arr[i+1]) && (i<=n-2)){
            swap(arr[i],arr[i+1]);
        }
    }
}
int main(){
    int arr[] = {7,3,9,9,10,3};
    int n = sizeof(arr)/sizeof(int);

    WaveSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//Time complexity of wave sort is O(n);