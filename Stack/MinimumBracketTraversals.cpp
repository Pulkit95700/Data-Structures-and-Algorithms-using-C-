#include<iostream>
#include<stack>
using namespace std;

// {{}}}}{{
int minimumBracketReversals(string s){
    if(s.length()%2 != 0){
        return -1;
    }
    int extraMoves = 0;
    
    if(s[0] == '}'){
        s = '{' + s;
        extraMoves+=1;
    }
        if(s[s.length()-1] == '{'){
        s = s + '}';
        extraMoves+=1;
    }
    stack<char> st;


    for(int i=0; i<s.length(); i++){
        if(s[i] == '{'){
            st.push(s[i]);
        }
        else if(s[i] == '}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
    int m = 0, n = 0;
    while(!st.empty()){
        if(st.top() == '{'){
            m+=1;
        }
        else if(st.top() == '}'){
            n+=1;
        }
        st.pop();
    }

    int res = (int)(m/2) + (int)(n/2) + extraMoves;

    return res;
}
int main(){
    string s = "}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{";
    cout<<minimumBracketReversals(s);
    return 0;
}

//Time Complexity O(n)
//extra Space Complexity O(n);