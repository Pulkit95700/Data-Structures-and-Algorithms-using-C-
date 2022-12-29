#include<iostream>
//In this we have to arrange the numbers in a way that numbers on the left are smaller than the pivot and those at th right are greater than the pivot
using namespace std;

int Partition_Second(int arr[], int l, int r){
    if(l > r){
        return -1;
    }

    int pivot = arr[l];
    int i=l, j=r;

    do{
        do{
            i++;
        }while(i>l && arr[i] <= pivot);

        do{
            j--;
        }while(j<r && arr[j] >= pivot);
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }while(i < j) ;

    swap(arr[l], arr[j]);

    return j;
}

void QuickSort(int arr[], int l, int r){
    if(l >= r){
        return;
    }

    int j = Partition_Second(arr, l, r);
    QuickSort(arr, l, j);
    QuickSort(arr, j+1, r);
}

int Partition(int arr[], int const l, int const r){
    if(l>r){
        return -1;
    }
    auto pivot = arr[r];
    auto i = l-1;// 6,3,2,2,5,9,8,7
    for(int j=l;j<r;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}

void QuickSort_Recursive(int arr[], int l, int r){
    if(l>r){
        return;
    }
    auto pivotIndex = Partition(arr, l, r);
    QuickSort_Recursive(arr, l, pivotIndex - 1);
    QuickSort_Recursive(arr, pivotIndex + 1, r);
}

int main(){

    int arr[] = {6,2,9,2,5,8,7};
    int n = sizeof(arr)/sizeof(int);

    QuickSort(arr,0, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

