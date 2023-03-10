#include<iostream>
#include<stack>
#include<string>

using namespace std;

void reverseSentence(string s){
    stack<string> st;
    string word = "";
    for(int i=0; i<s.length() ; i++){
        if(s[i] == ' '){
            st.push(word);
            word = "";
            continue;
        }
        word+=s[i];
    }
    st.push(word);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main(){
    string s = "Hey, how are you doing?";
    reverseSentence(s);
}