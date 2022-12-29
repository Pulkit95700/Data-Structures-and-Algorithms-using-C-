#include<iostream>
#include<queue>

using namespace std;

class Stack1{
    queue<int> q1;
    queue<int> q2;
    int N;

    Stack1(){
        N=0;
    }
    
    void push(int data){        //O(n)
        q2.push(data);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        N++;
        queue<int> temp;
        q1 = q2;
        q2 = temp;
    }

    int pop(){                  //O(1)
        if(!q1.empty()){

            int val = q1.front();
            q1.pop();
            N--;
            return val;

        }
    }

    int top(){              //O(1)
        return q1.front();
    }

    int size(){
        return N;
    }
    void display(){
        queue<int> temp = q1;

        while(!temp.empty()){
            cout<<temp.front()<<" ";
            temp.pop();
        }

    }
};
class Stack2{
    queue<int> q1;
    queue<int> q2;
    int n;
public:
    Stack2(){
        n=0;
    }

    void push(int data){  // O(1)
        q1.push(data);
        n++;
    }
    int top(){
        if(!q1.empty()){
            int val;
            while(!q1.empty()){  //O(n);
                val = q1.front();
                q2.push(val);
                q1.pop();
            }

            queue<int> temp;
            q1 = q2;
            q2 = temp;

            return val;
        }
    }
    int pop(){  //O(n)
        if(!q1.empty()){
            while(q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }

            int val = q1.front();
            q1.pop();

            queue<int> temp;
            q1 = q2;
            q2 = temp;

            n--;
            return val;
        }
    }
    int size(){
        return n;
    }
    void display(){
        queue<int> temp = q1;

        while(!temp.empty()){
            cout<<temp.front()<<" ";
            temp.pop();
        }
    }
};
int main(){

    Stack2 st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.size();
    cout<<st.pop();
    cout<<st.top();
    st.display();
    return 0;
}