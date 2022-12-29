//Question is to reverse k consecutive nodes inside the linked list.
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
    Node(int val){
        data = val;
        next = NULL;
    }

};

Node* ReverseNodes(Node* &head, int k){

    Node* prev = NULL;
    Node* current = head;
    Node* next;

    int count = 0;
    while(count<k && current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(next){
        head->next = ReverseNodes(next, k);
    }

    return prev;
}

int main(){

    Node* newHead = new Node(1);
    newHead->next = new Node(2);
    newHead->next->next = new Node(3);
    newHead->next->next->next = new Node(4);

    newHead = ReverseNodes(newHead, 2);
    while(newHead){
        cout<<newHead->data<<" -> ";
        newHead = newHead->next;
    }
    return 0;
}