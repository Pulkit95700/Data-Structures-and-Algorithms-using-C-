#include<iostream>
#include<deque>

using namespace std;

int max_deq(deque<int> d){
    int maxm = d.front();
    while(!d.empty()){
        maxm = max(maxm, d.front());
        d.pop_front();
    }

    return maxm;
}
void SlidingWindowMaximum(int* arr, int n, int k){  //Time Complexity O(k*n); 
    if(k>n){
        return;
    }

    deque<int> d;
    
    for(int i=0; i<k;i++){
        d.push_back(arr[i]);
    }

    cout<<max_deq(d)<<" ";

    for(int i=k; i<n; i++){
        d.pop_front();
        d.push_back(arr[i]);
        cout<<max_deq(d)<<" ";    
    }

}
int main(){

    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    SlidingWindowMaximum(arr, 8, 3);
    return 0;
}

