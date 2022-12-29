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

void PutEvenAfterOdd(Node* &head){
    Node* odd = head;
    Node* even = head->next;
    Node* evenStart = even;

    while(even->next!=NULL && odd->next!=NULL){  
        odd->next = even->next;
        odd = even->next;
        even->next = odd->next;
        even = odd->next;
    }

    odd->next = evenStart;
    if(odd->next != NULL){
        even->next = NULL;
    }
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    reorderList(head);
    Node* temp = head;
    while(temp){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    //2
    return 0;
}