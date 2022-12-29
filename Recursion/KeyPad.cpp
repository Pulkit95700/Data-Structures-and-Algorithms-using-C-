#include<iostream>
#include<string>
using namespace std;

string keyPad[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void GenerateAllKeypadCombinations(string s, string ans){
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string code = keyPad[ch-'0'];
    string ros = s.substr(1);

    for(int i=0;i<code.length();i++){
        GenerateAllKeypadCombinations(ros, ans+code[i]);
    }
}
int main(){
    
    string s="234";
    GenerateAllKeypadCombinations(s, "");
    return 0;
}

