#include<iostream>

using namespace std;

class Stack{
    int* arr;
    int top;
    int size;

    public:

    Stack(){
        size = 10;
        arr = new int[size];
        top = -1;
    }

    void manageOverflow(){
        int* newArr = new int[2*size];
        size = 2* size;
        for(int i=0;i<size;i++){
            newArr[i] = arr[i];
        }
        arr = newArr;
    }
    void push(int val){
        if(top == size-1){
            manageOverflow();
        }
        top++;
        arr[top] = val;
        return;
    }

    int pop(){
        if(isEmpty()){
            cout<<"no data in stack";
        }
        int temp = arr[top];
        top--;
        return temp;
    }

    int getTop(){
        if(isEmpty()){
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top==0;
    }
    void display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){

    Stack s;
    int j = 0;
    while(j<10){
        s.push(j); 
        j++;
    }
    // s.pop();
    // s.pop();
    cout<<s.getTop();
    s.display();
    return 0;
}