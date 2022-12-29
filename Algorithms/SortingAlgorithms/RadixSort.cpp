#include<iostream>
#include<string.h>

using namespace std;
void CountSort(int arr[], int n, int exp){

    int count_arr[10] = { 0 };
    
    for(int i=0; i<n; i++){
        count_arr[(arr[i] / exp) % 10]++;
    }

    for(int i=1; i<10; i++){
        count_arr[i] += count_arr[i-1];
    }

    int ans[n]; 

    for(int i=n-1; i>=0; i--){
        int idx = count_arr[(arr[i] / exp) % 10] - 1;
        ans[idx] = arr[i];
        count_arr[(arr[i] / exp) % 10]--;
    }

    for(int i=0; i<n; i++){
        arr[i] = ans[i];
    }
}
void RadixSort(int* arr, int n){
    O(d*1)
    int maxm = 0;

    for(int i=0; i<n; i++){
        maxm = max(maxm, arr[i]);
    }
    int exp = 1;
    while(maxm > 0){
        CountSort(arr, n, exp);
        exp = exp*10;
        maxm = maxm / 10;
    }
}

int main(){

    int arr[] = {1,5,2,5,1,1,3,8};
    int n = sizeof(arr)/sizeof(int);

    CountSort(arr, n, 1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}