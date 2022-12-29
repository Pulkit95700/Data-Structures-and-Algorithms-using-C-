#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool hasBalancedParenthesis(string s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            st.pop();
        }
    }

    return st.empty();
}
int main(){
    string sampleStr = "((3+5)-55)";
    cout<<hasBalancedParenthesis(sampleStr);
    return 0;
}