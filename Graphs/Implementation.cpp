#include<iostream>
#include<vector>

using namespace std;

//using adjacency matrix for non directional graph

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

vector<vector<int>> Adjacency_List(int vertices, int edges){
    vector<vector<int>> list(vertices + 1);

    for(int i=0; i<edges; i++){
        int u, v;
        cin>>u>>v;
        list[u].push_back(v);
        list[v].push_back(u);
    }

    return list;
}
int main(){

    // vector<vector<int>> matrix = Adjacency_Matrix(5,5);
    
    // for(int i=0; i<5; i++){
    //     for(int j=0; j<5; j++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<vector<int>> list = Adjacency_List(5, 5);

    for(int i=0; i<5; i++){
        cout<<i<<": ";
        for(int j=0; j<list[i].size(); j++){
            cout<<list[i][j]<<"->";
        }

        cout<<endl;
    }
    return 0;
}