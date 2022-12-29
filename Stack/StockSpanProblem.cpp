#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> StockSpanProblem(vector<int> v){

    vector<int> res(v.size(), 1);
    stack<int> st;

    for(int i=0; i<v.size(); i++){
        while(!st.empty() && v[st.top()] < v[i]){
            res[i]+=res[st.top()];
            st.pop(); 
        }
        st.push(i);
    }

    return res;
}
int main(){

    vector<int> v = {100, 80, 60, 70, 60, 75, 85};

    vector<int> res = StockSpanProblem(v);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}