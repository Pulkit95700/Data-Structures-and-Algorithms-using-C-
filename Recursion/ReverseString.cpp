#include<iostream>

using namespace std;


void ReverseString(char* s, int start, int end){
    if(start < end){
        swap(s[start],s[end]);
        ReverseString(s,start+1, end-1);
    }
}
int main(){

    char s[] = "binod";
    int n = sizeof(s)/sizeof(char);
    ReverseString(s,0,n-2);
    cout<<s;
    return 0;
}

