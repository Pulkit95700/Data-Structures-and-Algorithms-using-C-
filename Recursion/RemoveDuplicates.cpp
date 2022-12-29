#include<iostream>
#include<string>
using namespace std;

string RemoveDuplicates(string s){
    if(s[0] == '\0'){
        return "";
    }
    string restString =  RemoveDuplicates(s.substr(1));

    if(s[0] == restString[0]){
        return restString;
    }
    else{
        return s[0] + restString;
    }
}
int main(){
    string s = "ppullkiiityy";
    cout<<RemoveDuplicates(s);;
    return 0;
}

