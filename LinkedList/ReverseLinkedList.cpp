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
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList{
public:
    Node* head;
    int size = 0;

    LinkedList(){
        head = NULL;
    }
    LinkedList(Node* &head){
        this->head = head;
    }

    void append(int val){
        //making the pointer to the new node
        Node* n = new Node(val);
        if(head == NULL){
            head = n;
            size+=1;
            return;
        }
        //making a temporary pointer pointing the head node
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
        size+=1;
        return;
    }
    
    void Reverse(){
        Node* current = head;
        Node* previous = NULL;
        Node* next;


        while(current){     
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
            
        }
        head = previous;
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL";
    }
};

Node* ReverseRecursive(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = ReverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}
int main(){

    Node* head = new Node(1);
    LinkedList List(head);
    List.append(2);
    List.append(3);
    List.append(4);

    Node* newHead = new Node(1);
    newHead->next = new Node(2);
    newHead->next->next = new Node(3);
    newHead->next->next->next = new Node(4);

    newHead = ReverseRecursive(newHead);
    while(newHead){
        cout<<newHead->data<<" -> ";
        newHead = newHead->next;
    }
    List.Reverse();    
    // List.display();
    return 0;
}