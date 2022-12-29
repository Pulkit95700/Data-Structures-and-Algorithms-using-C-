#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> Previous_Greater_Element_With_Stack(vector<int> v){
    stack<int> st;
    vector<int> res;
    for(int i=0; i< v.size(); i++){
        while(!st.empty() && st.top() < v[i]){
            st.pop();
        }
        if(st.empty()){
            res.push_back(-1);
        }
        else{
            res.push_back(st.top());
        }
        st.push(v[i]);
    }
    return res;
}
int main(){

    vector<int> v{4, 10, 5, 8, 20, 15, 3, 12};

    vector<int> res = Previous_Greater_Element_With_Stack(v);

    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}