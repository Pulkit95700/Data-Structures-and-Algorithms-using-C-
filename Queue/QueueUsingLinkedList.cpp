#include<iostream>

using namespace std;

class Node{

public:

    int data;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }
    Node(int value){
        data = value;
        next = NULL;
    }
};
class Queue{
    
    Node* head;
    Node* tail;
    int size;

public:
    
    Queue(){
        head = NULL;
        tail = head;
        size = 0;
    }

    void enq(int data){ //Time Complexity O(1)
        size++;
        Node* n = new Node(data);
        if(head == NULL){
            head = n;
            tail = head;
            return;
        }
        tail->next = n;
        tail = tail->next;
    }

    int deq(){  //Time Complexity O(1)
        if(size != 0){
            int val = head->data;
            head = head->next;
            size--;
            return val;
        }
    }

    int peek(){
        return head->data;
    }

    int sizeOf(){
        return size;
    }

    int empty(){
        return size==0;
    }

    void display(){

        Node* temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};
int main(){

    Queue q;

    q.enq(1);
    q.enq(2);
    q.enq(3);

    q.deq();
    cout<<q.sizeOf()<<endl;
    q.display();
    return 0;
}

