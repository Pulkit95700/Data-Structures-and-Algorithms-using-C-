#include<iostream>

using namespace std;

class DoubleHash{
    int* arr;

    int hash1(int val){
        return val % 10;
    }

    int hash2(int val){
        return 7 - (val % 7);
    }

    int hash(int val, int i){
        return (hash1(val) + i*hash2(val)) % 10;
    }

public:

    DoubleHash(){
        arr = new int[10];
        for(int i=0; i<10; i++){
            arr[i] = -1;
        }
    }
    
    void Insert(int val){
        int i = 0;
        int key = hash(val, i);
        
        while(arr[key] != -1){
            i++;
            key = hash(val, i);
        }

        arr[key] = val;
    }

    bool Search(int val){
        int i=0;
        int key = hash(val, i);

        while(arr[key] != -1 && arr[key] != val){
            i++;
            key = hash(val, i);
        }

        return arr[key] == val;
    }

    void display(){
        for(int i=0; i<10; i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    DoubleHash d;
    d.Insert(2);
    d.Insert(22);
    d.Insert(32);
    d.Insert(92);

    cout<<d.Search(93);
    d.display();
    return 0;
}