#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(top);
}
void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
    return 0;
}