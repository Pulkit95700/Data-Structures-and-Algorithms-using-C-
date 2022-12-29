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

bool DetectCycle(Node* &head){
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next; 
        if(fast == slow){
            return true;
        }
    }

    return false;
}

void RemoveCycle(Node* head){
    if(head == NULL || head->next == NULL){
        return;
    }
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            break;
        }
    }
    if(slow != fast){
        return;
    }
    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;  
    }

    slow->next = NULL;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next= new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next= head->next;
    
    cout<<DetectCycle(head);
    RemoveCycle(head);
    cout<<DetectCycle(head);
    return 0;
}