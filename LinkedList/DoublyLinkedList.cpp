#include<iostream>

using namespace std;

class Node{
    public:
    int data = 0;
    Node* prev = NULL;
    Node* next = NULL;

    Node(){

    }

    Node(int val){
        data = val;
    }
};

class DoublyLinkedList{
    public:
    Node* head;

    DoublyLinkedList(int val){
        head = new Node(val);
    }

    void insertAtHead(int val){
        Node* n = new Node(val);
        if(head == NULL){
            head = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }
    void append(int val){
        Node* n = new Node(val);
        if(head == NULL){
            head = n;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        n->prev = temp;
        temp->next = n;
        return;
    }

    void deleteAtHead(){
        head = head->next;
        delete head->prev;
        head->prev = NULL;
        return;
    }
    void deleteAtPos(int pos){
        if(pos == 0){
            head = head->next;
            delete head->prev;
            head->prev = NULL;
            return;
        }

        int count = 0;
        Node* temp = head;
        while(count<pos && temp){
            temp = temp->next;
            count++;
        }

        temp->prev->next = temp->next;
        if(temp->next){
            temp->next->prev = temp->prev; //always think of the binary cases.
        }
        delete temp;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<"<-->";
            temp = temp->next;
        }
    }
};
int main(){

    DoublyLinkedList List(5);
    List.append(2);
    List.append(3);
    List.append(5);
    List.insertAtHead(7);
    List.deleteAtPos(0);
    List.display();
    return 0;
}
