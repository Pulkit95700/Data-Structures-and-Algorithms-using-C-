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
// class LinkedList{
//     public:
//         Node* head;
//         LinkedList(){
//             head = NULL;
//         }
//         LinkedList(int data){
//             head->data = data;
//         }
//         void append(int data){
//             Node* n = new Node(data);
//             if(head == NULL){
//                 head = n;
//                 return;
//             }
//             Node* temp = head;
//             while(temp->next){
//                 temp = temp->next;
//             }
//             temp->next = n;
//         }
// };

class Stack{

    Node* head;
    int numElements;
    public:
        Stack(){
            head = NULL;
            numElements = 0;
        }
        void push(int data){
            Node* n = new Node(data);

            if(head == NULL){
                head = n;
                numElements++;
                return;
            }
            n->next = head;
            head = n;
            
            numElements++;
        }

        int pop(){
            if(head == NULL){
                return -1;
            }
            Node* temp = head;
            head = head->next;

            int data = temp->data;
            numElements--;
            delete temp;

            return data;
        }

        int top(){
            if(head == NULL){
                return -1;
            }

            return head->data;
        }

        bool empty(){
            return numElements==0;
        }
        void display(){
            Node* temp = head;
            while(temp){
                cout<<temp->data<<"-->";
                temp = temp->next;
            }
        }
};

int main(){

    Stack s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    s.pop();
    cout<<s.empty();
    s.display();
    return 0;
}