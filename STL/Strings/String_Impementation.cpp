#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;


bool compare(char s1, char s2){
    return s1 < s2;
}
int main(){

    // Iniializing the string 
    string s1{"pulkit Gupta"};
    
    // Initializing a string with a String
    string s2(s1);
    string s3 = s1;

    
    cout<<s1<<endl;
    cout<<s2<<endl;

    // Append function

    s1.append(s2);
    s2+=s3;

    cout<<s1<<endl;

    s1.clear(); // clears everything from teh string
    cout<<s1<<endl;

    //comparison between the strings
    
    int cmp = s1.compare(s2); //negative if string is smaller and 0 if it is equal and 1 if it is greater
    cout<<cmp<<endl;

    // a funcion to find the elements in the string
    int index = s2.find("G");  //gives the starting index of the word given
    cout<<s1[index]<<endl;

    for(auto it: s2){   // here the it is the element itself not the iterator
        cout<<it<<endl;
    }
    
    // to delete from the string we use
    s2.erase(0, 4);
    // To sort strings

    const char* c = s2.c_str(); 

    cout<<c<<endl;

    
    return 0;
}