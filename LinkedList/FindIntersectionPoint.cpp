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

Node* FindIntersectionPointOfTwoLinkedList(Node* &head1, Node* &head2){
    int l1 = lengthOfLinkedList(head1);
    int l2 = lengthOfLinkedList(head2);

    if(l1>l2){
        Node* ptr1 = head1;
        Node* ptr2 = head2;
        int d= l1-l2;
    }
    else{
        Node* ptr1 = head2;
        Node* ptr2 = head1;
        int d = l2-l1;
    }

    while(d!=0){
        d--;
        if(ptr1 == NULL){
            return NULL;
        }
        ptr1 = ptr1->next;
    }
    while(ptr1 != ptr2 && ptr1 && ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if(ptr1 != ptr2 && ptr1){
        return NULL;
    }
    else{
        return ptr1;
    }
}
int main(){
    
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next= new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    Node* ans = FindIntersectionPointOfTwoLinkedList(head)

    Node* temp = head;
    while(temp){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    return 0;
}