#include<iostream>
#include<string>
using namespace std;

string MoveXToEnd(string s){
    if(s[0] == '\0'){
        return "";
    }
    string restString =  MoveXToEnd(s.substr(1));
    if(s[0] == 'x'){
        return restString + s[0];
    }
    else{
        return s[0] + restString;
    }
}
int main(){
    string s = "axxbdxcefxhix";
    cout<<MoveXToEnd(s);;
    return 0;
}

