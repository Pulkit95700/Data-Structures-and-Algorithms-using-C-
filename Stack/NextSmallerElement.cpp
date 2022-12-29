#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> Next_Smaller_Element_With_Stack(vector<int> v){
    if(v.size() == 0){
        return v;
    }
    stack<int> st;
    vector<int> res(v.size());
    for(int i=v.size()-1; i>=0; i--){
        while(!st.empty() && st.top() > v[i]){
            st.pop();
        }
        if(st.empty()){
            res[i] = -1;
        }
        else{
            res[i] = st.top();
        }
        st.push(v[i]);
    }

    return res;
}
int main(){

    vector<int> v{4, 10, 5, 8, 20, 15, 3, 12};
    vector<int> value = Next_Smaller_Element_With_Stack(v);

    for(auto i: value){
        cout<<i<<" ";
    }
    return 0;
}