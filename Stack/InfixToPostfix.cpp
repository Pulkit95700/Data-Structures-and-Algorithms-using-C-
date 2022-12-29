#include<iostream>
#include<stack>
#include<string>

using namespace std;

int prec(char c){
    if(c == '^'){ return 3;}
    else if(c == '*' || c=='/'){return 2;}
    else if(c == '+' || c=='-'){return 1;}
    else{return -1;}
}
string InfixToPostfix(string s){
    stack<char> st;
    string res;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '('){
            st.push('(');
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){st.pop();}
        }
        else if(s[i] <= 'z' && s[i] >= 'a' || s[i] <= 'Z' && s[i] >= 'A'){
            res+=s[i];
        }
        else{
            while(!st.empty() && prec(st.top()) != -1 && prec(st.top()) > prec(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }

    return res;
}
int main(){
    cout<<InfixToPostfix("(a-b/c)*(a/k-l)");
    return 0;
}