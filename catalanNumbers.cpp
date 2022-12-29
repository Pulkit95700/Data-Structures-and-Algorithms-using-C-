#include<iostream>

using namespace std;

// int catalan(int n){
//     if(n == 0 || n == 1){
//         return 1;
//     }

//     int res = 0;
//     for(int i=0; i<n; i++){
//         res+=catalan(i)*catalan(n-i-1);
//     }

//     return res;
// }


int main(){
    int n;
    cin>>n;
    int catalan[n];
    catalan[0] = 1;
    catalan[1] = 1;
    cout<<catalan[0]<<" "<<catalan[1]<<" ";
    for(int i=2; i<n; i++){
        catalan[i] = 0;
        for(int j=0; j< i; j++){
            catalan[i] += catalan[j]*catalan[i-j-1]; 
        }
        cout<<catalan[i]<<" ";
    }
    return 0;
}