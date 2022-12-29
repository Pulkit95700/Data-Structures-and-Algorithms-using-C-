#include<iostream>
#include<string>
using namespace std;

void GenerateAllSubstringsWithAscii(string s, string ans){
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string ros =  s.substr(1);

    GenerateAllSubstringsWithAscii(ros, ans);
    GenerateAllSubstringsWithAscii(ros, ans+ch);
    GenerateAllSubstringsWithAscii(ros, ans+to_string(int(ch)));
}
int main(){
    string s = "AB";
    GenerateAllSubstringsWithAscii(s, "");
    return 0;
}

