#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> Next_Greater_Element_With_Stack(vector<int> v){
    vector<int> res(v.size());
    stack<int> st;

    for(int i = v.size()-1; i>=0; i--){
        while(!st.empty() && st.top() < v[i]){
            st.pop();
        }

        if(st.empty()){
            res[i] = -1;
        }else{
            res[i] = st.top();
        }
        st.push(v[i]);
    }
    return res;
}
int main(){
        vector<int> v{4, 10, 5, 8, 20, 15, 3, 12};

    vector<int> res = Next_Greater_Element_With_Stack(v);

    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}