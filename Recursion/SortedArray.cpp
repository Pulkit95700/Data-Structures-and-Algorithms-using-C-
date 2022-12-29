#include<iostream>

using namespace std;

template<typename T>

bool CheckSortedArray(T* arr,int n){
    if(n==1){
        return true;
    }
    return (arr[0]<arr[1] && CheckSortedArray(arr+1, n-1));
}
int main(){

    int arr[] = {1,2,3,7,0};
    int n = sizeof(arr)/sizeof(int);

    cout<<CheckSortedArray(arr, n);
    return 0;
}

//In the above code it is checked that whether the first and second are sorted and then we passed the rest array to the function.
