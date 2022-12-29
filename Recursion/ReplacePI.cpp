#include<iostream>
#include<string>
using namespace std;


void ReplacePiWithValue(string s,int i=0,float value = 3.14){
    if(i<s.length()){
        if(s[i] == 'p' && s[i+1] == 'i'){
            cout<<value;
            ReplacePiWithValue(s, i+2);
        }
        else{
            cout<<s[i];
            ReplacePiWithValue(s,i+1);
        }
    }
}
int main(){

    string s = "pi";
    int n = s.length();
    ReplacePiWithValue(s);
    return 0;
}

