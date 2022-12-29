#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int>> Adjacency_Matrix(int vertices, int edges){
    vector<int> v(vertices, 0);
    vector<vector<int>> matrix(vertices, v);
    
    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;
        matrix[u-1][v-1] = 1;
        matrix[v-1][u-1] = 1;
    }

    return matrix;
}

void DepthFirstSearch(vector<vector<int>> matrix, int starting_point = 1){
    stack<int> st;
    st.push(0);
    
    vector<bool> visited(matrix.size(), 0);
    bool flag = false;
    visited[starting_point] = 1;
    
    while(!st.empty()){
        int vertex = st.top();
        flag = 0;
        int i=0;

        while(i < matrix.size()){
            if(!visited[i]){
                flag = true;
                visited[i] = true;
                cout<<i<<" ";
                st.push(i);
                break;
            }
            i++;
        }
      
        if(!flag && !st.empty()){
            st.pop();
        }
    }
}

void Depth_First_Search_Recursion(vector<vector<int>> matrix, int starting_point = 0){
    
    static vector<bool> visited(matrix.size(), 0);
    visited[starting_point] = 1;
    cout<<starting_point + 1<<" ";
    for(int i=0; i<matrix.size(); i++){
        if(!visited[i] && matrix[starting_point][i] == 1){
            visited[i] = 1;
            Depth_First_Search_Recursion(matrix, i);
        }
    }

}

int main(){

    vector<vector<int>> matrix = Adjacency_Matrix(6, 6);

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix.size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    Depth_First_Search_Recursion(matrix, 0);
    return 0;
}