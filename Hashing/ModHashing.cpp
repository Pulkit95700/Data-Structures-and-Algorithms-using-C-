#include<iostream>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

class ModHash{
    Node** arr;

    int hash(int val){
        return val % 10;
    }
public:
    ModHash(){
        arr = new Node*[10];
        for(int i=0; i<10; i++){
            arr[i] = NULL;
        }
    }

    void Insert(int val){
        int key = hash(val);
        
        if(arr[key] == NULL){
            arr[key] = new Node(val);
            return;
        }

        Node* temp = arr[key];
        Node* prev;

        while(temp && temp->val < val){
            prev = temp;
            temp = temp->next;
        }

        prev->next = new Node(val);
        prev->next->next = temp;

        return;
    }

    bool Search(int val){
        int key = hash(val);

        Node* temp = arr[key];

        if(temp == NULL) return false;
    
        while(temp && temp->val <= val){
            if(temp->val == val){return true;}
            temp = temp->next;
        }

        return false;
    }

    void Delete(int val){
        int key = hash(val);

        Node* temp = arr[key];
        Node* prev;
        if(temp == NULL){return;}

        if(temp->val == val){
            arr[key] = temp->next;
            delete temp;
            return;
        }

        while(temp && temp->val < val){
            prev = temp;
            temp = temp->next;
        }

        if(!temp){return;}
        if(temp->val != val){return;}

        prev->next = temp->next;
        delete temp;
        return;
    }
    
    void display(){
        for(int i=0; i<10; i++){
            Node* head = arr[i];
            while(head){
                cout<<head->val<<"->";
                head = head->next;
            }
            if(arr[i]){cout<<endl;}
        }
    }
};
int main(){
    ModHash m;
    m.Insert(1);
    m.Insert(3);
    m.Insert(11);
    m.Insert(31);
    m.Insert(21);
    m.Insert(0);
    m.Delete(1);
    // cout<<m.Search(1);
    m.display();
    return 0;
}