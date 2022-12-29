#include<iostream>

using namespace std;

class QuadraticProbing{
    int* arr;

    int hash(int val, int i){
        return (val % 10 + i*i) % 10;
    }
public:

    QuadraticProbing(){
        arr = new int[10];
        for(int i=0; i<10; i++){
            arr[i] = -1;
        }
    }

    void Insert(int val){
        int i=0;
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

    QuadraticProbing q;
    q.Insert(1);
    q.Insert(11);
    q.Insert(31);

    q.display();
    return 0;
}