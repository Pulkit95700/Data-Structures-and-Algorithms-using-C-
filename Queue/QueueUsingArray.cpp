#include<iostream>

using namespace std;

class Queue{    

    int* arr;
    int back;
    int capacity;
    int front;
    public:
    Queue(int cap = 10){
        capacity = 10;
        arr = new int(cap);
        back = -1;
        front = -1; 
    }

    void handleCapacity(){
        int* newArr = new int[capacity*2];
        for(int i=front;i<back;i++){
            newArr[i] = arr[i];
        }
        delete arr;
        arr = newArr;
    }
    void enqueue(int x){
        if(back == capacity -  1){
            handleCapacity();
        }
        back++;
        if(back == 0){
            arr[back] = x;
            front++;
        }
        else{
            arr[back] = x;
        }
    }

    int dequeue(){     
        if(empty()){
            return -1;
        }
        int value = arr[front];
        front++;
        return value;
    }

    int peek(){
        return arr[front];
    }

    int empty(){
        return front > back;
    }

    int size(){
        return back - front + 1;
    }
    void display(){
        for(int i=front; i <= back; i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(33);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    // q.dequeue();


    q.display();
    return 0;
}