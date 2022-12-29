#include<iostream>
#include<stack>
#include<queue>

using namespace std;

queue<int> ReverseQueue(queue<int> q){
    stack<int> st;

    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    return q;
}
int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q = ReverseQueue(q);
    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }
    return 0;
}

//Time Complexity is O(n) as we are traversing n elements two times.