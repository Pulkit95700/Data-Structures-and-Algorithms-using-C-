#include<iostream>
#include<string>
using namespace std;


void TowerOfHanoi(int n, char s = 'S', char a = 'A', char d= 'D'){
    if(n<=0){
        return;
    }
    TowerOfHanoi(n-1, s, d, a);
    cout<<s<<d<<endl;
    TowerOfHanoi(n-1, a, s, d);
}
int main(){

    TowerOfHanoi(3);
    return 0;
}

