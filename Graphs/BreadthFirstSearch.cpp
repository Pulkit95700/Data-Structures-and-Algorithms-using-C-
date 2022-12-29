#include<iostream>
#include<vector>
#include<queue>

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


void Breadth_First_Search(vector<vector<int>> matrix, int starting_point = 0){
    int vertices = matrix.size();
    vector<bool> visited(vertices, 0);

    visited[starting_point] = 1;
    
    queue<int> q;
    q.push(starting_point);

    while(!q.empty()){
        int vertex = q.front();
        cout<<vertex<<" ";
        int i=0;
        
        while(i < vertices){
            if(matrix[vertex][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = 1;
             
            }
            i++;
        }

        q.pop();
    }

}

int main(){

    vector<vector<int>> matrix = Adjacency_Matrix(5, 7);

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix.size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    Breadth_First_Search(matrix, 4);

    return 0;
}