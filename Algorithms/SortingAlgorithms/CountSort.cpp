#include<iostream>

using namespace std;

void CountSort(int arr[], int n){
    int minm = arr[0];
    int maxm = arr[0];

    for(int i=0; i<n; i++){
        minm = min(minm, arr[i]);
        maxm = max(maxm, arr[i]);
    }

    if(minm < 0){
        return;
    }

    int count_arr[maxm - minm + 1] = { 0 };

    for(int i=0; i<n; i++){
        count_arr[arr[i] - minm]++;
    }

    for(int i=1; i<maxm - minm + 1; i++){
        count_arr[i] = count_arr[i-1] + count_arr[i];
    }
    
    int ans[n];

    for(int i=n-1; i>=0; i--){
        count_arr[arr[i] - minm]--;
        ans[count_arr[arr[i] - minm]] = arr[i];
    }

    for(int i=0; i<n; i++){
        arr[i] = ans[i];
    }
}

int main(){
    int arr[] = {7,2,6,2,7,0,2};
    int n = sizeof(arr)/sizeof(int);
    CountSort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}