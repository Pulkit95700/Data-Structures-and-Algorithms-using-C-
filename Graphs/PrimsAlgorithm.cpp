#include<bits/stdc++.h>
using namespace std;

unordered_map<int, list<pair<int, int>>> Adjacency_Matrix(int vertices, int edges){
    unordered_map<int, list<pair<int, int>>> mat;

    // for a graph 

    for(int i=0; i<edges; i++){
        int u, v, w;
        cin>>u>>v>>w;

        mat[u].push_back(make_pair(v, w));
        mat[v].push_back(make_pair(u, w));

    }

    return mat;
}

void PrimsMinimumCostSpanningTree(unordered_map<int, list<pair<int, int>>> graph, int n, int m){
    vector<int> key(n+1, INT_MAX);
    vector<bool> mstSet(n+1, 0);
    vector<int> parent(n+1, -1);

    key[1] = 0;
    parent[1] = -1;
    for(int i=1; i<=n; i++){

        int minm = INT_MAX;
        int u;

        // finding the minimum node

        for(int v=1; v<=n; v++){
            if(mstSet[v] == false && key[v] < minm){
                u = v;
                minm = key[v];
            }
        }

        // marking minimum node as true
        mstSet[u] = true;

        for(auto it:graph[u]){
            int v = it.first;
            int w = it.second;

            if(mstSet[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w; 
            }
        }
    }


    vector<pair<pair<int, int>, int>> result;

    for(int i=2; i<=n; i++){
        result.push_back(make_pair(make_pair(parent[i], i), key[i]));
        cout<<parent[i]<<" "<<i<<" "<<key[i]<<endl;
    }

}
int main(){
    unordered_map<int, list<pair<int, int>>> graph = Adjacency_Matrix(5, 6);

    cout<<"answer"<<endl;
    PrimsMinimumCostSpanningTree(graph, 5, 6);
    return 0;
}