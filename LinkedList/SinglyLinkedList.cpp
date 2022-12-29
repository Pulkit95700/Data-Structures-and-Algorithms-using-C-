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
        this->head->next = NULL;
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
    void insertAtHead(int val){
        Node* n = new Node(val);
        if(head == NULL){
            head = n;
            return;
        }
        n->next = head;
        head = n;
        return;
    }

    bool search(int val){
        Node* temp = head;
        int index = 0;
        while(temp){
            if(temp->data == val){
                return true;
            }
            temp = temp->next;
            index++;
        }

        return false;
    }

    void Delete(int val){
        Node* temp = head;
        if(temp->data == val){
            head = head->next;
            delete temp;
            return;
        }
        while(temp->next->data != val && temp){
            temp = temp->next;
        }

        Node* todelete = temp->next;
        temp->next = temp->next->next;
        
        delete todelete;
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL";
    }

    void insertAtPos(int val, int pos){
        int index = 0;
        Node* n = new Node(val);
        if(pos == 0){
            n->next = head;
            head = n;
            return;
        }
        Node* temp = head;
        while(index<pos-1 && temp){
            temp = temp->next;
            index++;
        }
        if(temp == NULL) return;
        n->next = temp->next;
        temp->next = n;
        return;
    }

    
};
int main(){

    Node* head = new Node(1);
    LinkedList List(head);
    List.append(2);
    List.append(3);
    List.insertAtHead(4);
    // List.Delete(2);
    List.insertAtPos(20,20);
    List.display();
    return 0;
}