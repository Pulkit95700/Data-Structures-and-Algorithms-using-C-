#include<bits/stdc++.h>

using namespace std;

class Queue{

    stack<int> st;
    public:

    // push the item into the stack O(1)
    //to deq pop the items and push it into the another stack and return the last item of the stack and giving refernce fo another stack to old stack
    Queue(){
        
    }

    void enq(int data){
        st.push(data);
    }

    int deq(){  //Time Complexity O(2n)
        if(!st.size() == 0){
            stack<int> tempStack;
            int last = -1;
            while(!st.empty()){
                last = st.top();
                tempStack.push(last);
                st.pop();
            }
            tempStack.pop();
            while(!tempStack.empty()){
                st.push(tempStack.top());
                tempStack.pop();
            }

            return last;
        }
    }

    void display(){
        for(auto it:st){
            cout<<*(it)<<" ";
        }
    }
};

int main(){
    
    Queue q;
    q.enq(1);
    q.enq(2);
    q.enq(3);
    q.enq(4);
    cout<<q.display();
    cout<<q.deq();
    cout<<q.deq();
    cout<<q.deq();
    cout<<q.deq();

    return 0;
}