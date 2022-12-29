#include<iostream>

using namespace std;

template<typename T>

void PrintNumbersAscending(T start, T end){
    if(start<=end){
        cout<<start<<" ";
        PrintNumbersAscending(start+1, end);
    }
}
template<typename T>
void PrintNumbersDescending(T start, T end){
    if(start>=end){
        cout<<start<<" ";
        PrintNumbersDescending(start-1, end);
    }
}
int main(){

    int arr[] = {1,2,3,7,0};
    int n = sizeof(arr)/sizeof(int);

    PrintNumbersAscending(1,10);
    PrintNumbersDescending(10,1);

    return 0;
}

