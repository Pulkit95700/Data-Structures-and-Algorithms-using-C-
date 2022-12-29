#include<iostream>

using namespace std;

class Heap{

    int* arr;
    int size;
    int capacity;
public:
    Heap(int capacity){
        arr = new int[capacity];
        size = 0;
        this->capacity = capacity;
    }

    void UP_HEAPIFY(int index){
        int parent_index = (index + 1)/2 - 1;
        while(arr[parent_index] < arr[index]){
            swap(arr[parent_index], arr[index]);
            index = parent_index;
            parent_index = (index + 1)/2 - 1;
        }
    }

    void insert(int val){
        if(size == 0){
            arr[size] = val;
            size++;
            return;
        }
        if(size < capacity){
            arr[size] = val;
            UP_HEAPIFY(size);
            size++;
        }
    }

    void DOWN_HEAPIFY(){
        int index = 0;
        int left_child_index = 2*(index + 1) - 1;
        int right_child_index = 2*(index + 1);
        while(true){
            if(right_child_index < size && arr[right_child_index] > arr[left_child_index]){
                if(arr[right_child_index] > arr[index]){
                    swap(arr[right_child_index], arr[index]);
                    index = right_child_index;
                }
                else{   
                    break;
                }
            }else if(left_child_index < size && arr[left_child_index] > arr[right_child_index]){
                if(arr[left_child_index] > arr[index]){
                    swap(arr[left_child_index], arr[index]);
                    index = left_child_index;
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
            left_child_index = 2*(index + 1) - 1;
            right_child_index = 2*(index + 1);
        }
    }

    int Delete(){
        if(size == 0){
            return -1;
        }
        if(size == 1){
            size--;
        }
        size--;
        int x = arr[0];
        arr[0] = arr[size];
        DOWN_HEAPIFY();
        return x;
    }

    void display(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){

    int arr[] = {6,3,8,9,2,4,1};
    int n = sizeof(arr)/sizeof(int);
    Heap h(n);
    
    for(int i=0; i<n; i++){
        h.insert(arr[i]);
    }

    for(int i=0; i<n; i++){
        arr[n-i-1] = h.Delete();
    }

    for(int i=0; i< n; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}