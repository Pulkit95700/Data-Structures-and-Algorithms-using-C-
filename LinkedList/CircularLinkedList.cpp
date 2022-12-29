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

class CircularLinkedList{
    public:
    Node* head = NULL;
    
    CircularLinkedList(){

    }
    void insertAtHead(int val){
        Node* n = new Node(val);
        if(head == NULL){
            n->next = n;
            head = n;
            return;
        }
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        n->next = head;
        temp->next = n;
        head = n;
    }
    void append(int val){
        if(head == NULL){
            insertAtHead(val);
            return;
        }
        Node* n = new Node(val);
        Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }

    void display(){
        Node* temp = head;
        do{
            cout<<temp->data<<"-->";
            temp = temp->next;
        }while(temp != head);
    }
    void DeleteAtHead(){
        Node* temp = head;

        while(temp->next != head){
            temp = temp->next;
        }
        Node* toDelete = head;
        temp->next = head->next;
        head = head->next;

        delete toDelete;

    }
    void DeleteAtPos(int pos){
        Node* temp = head;
        if(pos == 0){
            DeleteAtHead();
            return;
        }
        int count = 1;
        while(count<pos){
            temp = temp->next;
            count++;
        }
        if(temp == head){
            DeleteAtHead();
        }
        Node* n = temp->next;
        temp->next = temp->next->next;
        delete n;
        return;
    }
};
int main(){

    CircularLinkedList circL;
    circL.append(1);
    circL.append(2);
    circL.append(3);
    circL.append(4);
    circL.DeleteAtPos(5);
    circL.display();

    return 0;
}
