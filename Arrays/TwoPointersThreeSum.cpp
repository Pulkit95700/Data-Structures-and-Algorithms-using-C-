#include<bits/stdc++.h>
#include<vector>

using namespace std;

bool TwoPointersThreeSumApproach(int arr[], int n, int target){
    sort(arr, arr+n);
    bool found = false;
    for(int i=0; i<n-1;i++){
        int low = i+1, high = n-1;
        while(low < high){
            int sum = arr[low] + arr[high];
            if(sum == target - arr[i]){
                found = true;
            }
            if(sum > target - arr[i]){
                high--;
            }
            else{
                low++;
            }
        }
    }

    return found;
}
int main(){

    int arr[] = {12, 3, 7, 1, 6, 9};
    cout<<TwoPointersThreeSumApproach(arr, 6, 5);
    return 0;
}