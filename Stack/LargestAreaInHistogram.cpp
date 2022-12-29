#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int Largest_Area_In_Histogram_With_Stack(vector<int> v){
    stack<int> stLeftSmaller;
    stack<int> stRightSmaller;

    vector<int> left(v.size());
    vector<int> right(v.size());

    int maxArea = 0;

    for(int i=0; i<v.size(); i++){
        while(!stLeftSmaller.empty() && v[stLeftSmaller.top()] > v[i]){
            stLeftSmaller.pop();
        } 
        left[i] = stLeftSmaller.empty() ? -1 : stLeftSmaller.top();
        stLeftSmaller.push(i);
    }
    for(int i=v.size() -1 ; i>=0; i--){
        while(!stRightSmaller.empty() && v[stRightSmaller.top()] > v[i]){
            stRightSmaller.pop();
        } 
        right[i] = stRightSmaller.empty() ? v.size() : stRightSmaller.top();
        stRightSmaller.push(i);
    }
    for(int i=0; i<v.size(); i++){
        maxArea = max(maxArea, (right[i] - left[i] - 1) * v[i]);
    }

    return maxArea;
}
int main(){

    vector<int> v{6, 2, 5, 4, 5, 1, 6};

    int res = Largest_Area_In_Histogram_With_Stack(v);

    cout<<res;
    return 0;
}