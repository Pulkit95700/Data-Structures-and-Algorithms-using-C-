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

Node* Merge2SortedLinkedListRecursive(Node* head1, Node* head2){
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    
    Node* head;
    if(head1->data < head2->data){
        head = head1;
        head->next = Merge2SortedLinkedListRecursive(head1->next, head2);
    }
    else{
        head = head2;
        head->next = Merge2SortedLinkedListRecursive(head1, head2->next);
    }

    return head;
}
Node* Merge2SortedLinkedList(Node* head1, Node* head2){
    Node* head = new Node();
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* temp = head;
    while(ptr1 && ptr2){
        if(ptr1->data < ptr2->data){
            temp->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            temp->next = ptr2;
            ptr2 = ptr2->next;
        }
        temp = temp->next;
    }

    while(ptr1){
        temp->next = ptr1;
        ptr1 = ptr1->next;
        temp = temp->next;

    }
    while(ptr2){
        temp->next = ptr2;
        ptr2 = ptr2->next;
        temp = temp->next;

    }
    return head->next;
}
int main(){

    Node* head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(6);

    Node* secHead = new Node(2);
    secHead->next = new Node(3);
    secHead->next->next = new Node(5);

    Node* sortedHead = Merge2SortedLinkedListRecursive(head, secHead);

    Node* temp = sortedHead;
    while(temp){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    return 0;
}

