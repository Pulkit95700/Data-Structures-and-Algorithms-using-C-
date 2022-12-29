#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Deque{
    Node* head;
    Node* tail;
    int N;
public:
    Deque(){
        head = NULL;
        N = 0;
        tail = NULL;
    }

    void push_back(int val){
        Node* n = new Node(val);
        N++;
        if(head == NULL){
            head = n;
            tail = n;
            return;
        }

        n->prev = tail;
        tail->next = n;
        tail = n;

        return;
    }

    void push_front(int val){
        Node* n = new Node(val);
        N++;
        if(head == NULL){
            head = n;
            tail = n;
            return;
        }

        n->next = head;
        head->prev = n;
        head = n;
        return;
    }

    int pop_back(){
        if(N != 0){

            Node* n = tail;
            tail = tail->prev;
            tail->next = NULL;
            int val = n->data;
            n->prev = NULL;
            delete n;
            N--;
            return val;
        }
    }

    int pop_front(){
        if(N!=0){
            Node* n = head;
            head = head->next;
            head->prev = NULL;

            int val = n->data;
            n->next = NULL;

            delete n;
            N--;
            return val;
        }
    }

    int size(){
        return N;
    }


    void display(){
        Node* temp = head;
        while (temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        
    }
};

int main(){
    Deque d;

    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);

    d.push_front(5);
    d.pop_front();
    d.pop_back();
    d.pop_back();
    d.pop_back();
    d.pop_back();

    d.display();
    
    return 0;
}