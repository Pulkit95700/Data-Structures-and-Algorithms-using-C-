#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int Trapping_Rainwater_Brute_Force(vector<int> v){
    
    stack<int> st;
    int res = 0;
    int leftMax = -1, rightMax = -1;
    for(int i=0; i<v.size(); i++){
        leftMax = rightMax = v[i];
        for(int j=i-1; j>=0; j--){
            leftMax = max(leftMax, v[j]);
        }
        for(int j=i+1; j<v.size(); j++){
            rightMax = max(rightMax, v[j]);
        }
 
        res+=(max(0, min(leftMax, rightMax) - v[i]));

    }
    return res;
}

int Trapping_Rainwater_With_Efficient(vector<int> v){

    vector<int> leftMax(v.size());
    vector<int> rightMax(v.size());
    int res = 0;
    leftMax[0] = v[0];
    rightMax[v.size() - 1] = v[v.size() - 1];

    for(int i=1; i<v.size(); i++){
        leftMax[i] = max(leftMax[i-1], v[i]);
        
    }
    
    for(int i=v.size()-2; i>=0; i--){
        rightMax[i] = max(rightMax[i+1], v[i]);     
    }

    for(int i=0; i<v.size(); i++){
        res += min(leftMax[i], rightMax[i]) - v[i];
    }

    return res;

}

int Trapping_Rainwater_With_Stack(vector<int> v){
    
    stack<int> st;
    int ans = 0;

    for(int i=0; i<v.size(); i++){
        while(!st.empty() && v[i] > v[st.top()]){
            int top = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int distance = i - st.top() - 1;
            int bounded_height = min(v[st.top()], v[i]) - v[top];

            ans+=bounded_height*distance;
        }
        st.push(i);
    }

    return ans;
}
int main(){

    vector<int> c{0,1,0,2,1,0,1,3,2,1,2,1};
    
    int res = Trapping_Rainwater_Brute_Force(c);
    int res_with_effiecient = Trapping_Rainwater_With_Efficient(c);
    int res_with_stack = Trapping_Rainwater_With_Stack(c);
    cout<<res<<" ";
    cout<<res_with_effiecient<<" ";
    cout<<res_with_stack;
    return 0;
}