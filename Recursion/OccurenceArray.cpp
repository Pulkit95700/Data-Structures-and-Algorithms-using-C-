#include<iostream>

using namespace std;

template<typename T>

int firstOccurence(T* arr, int n, int i, int k){
    if(i==n){
        return -1;
    }
    if(arr[i] == k){
        return i;
    }

    return firstOccurence(arr,n,i+1,k);
    
}
template<typename T>

int LastOccurence(T* arr, int n, int i, int k){
    if(i==n){
        return -1;
    }
    if(arr[i] == k){
        int index = LastOccurence(arr,n,i+1,k);
        if(index != -1){
            return index;
        }
        return i;
    }
    return LastOccurence(arr,n,i+1,k);
}
int main(){

    int arr[] = {1,2,3,7,5,1,0};
    int n = sizeof(arr)/sizeof(int);

    cout<<firstOccurence(arr, n, 0, 7);
    cout<<LastOccurence(arr, n, 0, 1);


    return 0;
}

