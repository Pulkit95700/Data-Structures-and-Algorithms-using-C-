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

    void Delete(){
        if(size == 0){
            return;
        }
        if(size == 1){
            size--;
        }
        size--;
        arr[0] = arr[size];
        DOWN_HEAPIFY();
    }

    void display(){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){
    Heap h(20);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(15);
    h.insert(25);
    h.insert(6);
    h.insert(5);

    h.Delete();
    h.display();
    return 0;
}
