#include<iostream>
#include<string>
using namespace std;

int GenerateAllSubstrings(string s, string ans){
    static int count = 0;
    if(s.length() == 0){
        count++;
        return count;
    }
    char ch = s[0];
    string ros =  s.substr(1);

    GenerateAllSubstrings(ros, ans);
    GenerateAllSubstrings(ros, ans+ch);

    return count;
}
int main(){
    string s = "abc";
    cout<<GenerateAllSubstrings(s, "");
    return 0;
}

