#include<iostream>
#include<vector>
using namespace std;

int main(){ 
    //  storing a graph
    int m,n;
    cin >> m >> n;
    // 1st method
            int adj[m+1][n+1];
            for(int i = 0;i<m;i++){
                int u,v;
                cin >> u >> v;
                adj[u][v] = 1;
                adj[v][u] = 1;
            }
    // second method
            vector<int> adjs[m+1];
            for(int i =0;i<n;i++){
                int u,v;
                cin >> u >> v;
                adjs[u].push_back(v);
                adjs[v].push_back(u);
            }
}