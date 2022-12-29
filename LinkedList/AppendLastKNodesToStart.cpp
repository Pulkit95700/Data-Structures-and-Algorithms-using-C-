#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next = NULL;

    Node(){
        data = 0;
    }
    Node(int val){
        data = val;
    }
};
int lengthOfLinkedList(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}

void AppendLastKNodesToStart(Node* &head, int k){
    int l = lengthOfLinkedList(head);
    if(k>l){
        k=k%l;
    }
    Node* lastNode = head;
    while(lastNode->next){
        lastNode = lastNode->next;
    }

    Node* newTailNode = head;
    int count = 1;
    while(count<l-k){
        newTailNode = newTailNode->next;
        count++;
    }
    lastNode->next = head;
    head = newTailNode->next;
    newTailNode->next = NULL;
}
int main(){
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next= new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    AppendLastKNodesToStart(head, 9);

    Node* temp = head;
    while(temp){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    return 0;
}