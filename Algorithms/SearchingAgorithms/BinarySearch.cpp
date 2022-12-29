#include<iostream>

using namespace std;

template<typename T>
int binarySearch(T* arr, int start, int end, T key){
    if(start > end){
        return -1;
    }
    else if(end==0){
        return arr[0] == key ? 0 : -1;
    }
    else{
        int mid = (start + end)/2;
        int index = -1;
        if(key < arr[mid]){
            index = binarySearch(arr, start, mid-1, key);
        }
        else if(key > arr[mid]){
            index = binarySearch(arr, mid+1, end, key);
        }
        else{
            index = mid;
        }
        return index;
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    int index = binarySearch(arr, 0, 4, 6);
    cout<< index;
}