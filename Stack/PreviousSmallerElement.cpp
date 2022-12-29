#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> Previous_Smaller_Element_Brute_Force(vector<int> v){
    vector<int> prevElement;
    for(int i=0; i < v.size(); i++){
        for(int j=i-1; j>=0; j--){
            if(v[j] <= v[i]){
                prevElement.push_back(v[j]);
                break;
            }
        }
        if(prevElement.size() < i+1){
            prevElement.push_back(-1);
        }
    }

    return prevElement;
}

vector<int> Previous_Smaller_Element_With_Stack(vector<int> v){
    vector<int> res;
    stack<int> st;
    st.push(-1);
    for(int i=0; i<v.size(); i++){
        while(st.top() != -1 && st.top() > v[i]){
            st.pop();
        }
        
        res.push_back(st.top());
        st.push(v[i]);
    }

    return res;
}
int main(){

    vector<int> v{4, 10, 5, 8, 20, 15, 3, 12};
    // vector<int> value = Previous_Smaller_Element_Brute_Force(v);
    vector<int> value = Previous_Smaller_Element_With_Stack(v);

    for(auto i: value){
        cout<<i<<" ";
    }
    return 0;
}