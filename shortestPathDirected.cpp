#include<iostream>
#include<vector>
#include<queue>


using namespace std;


int  main(){
    vector<vector<int>> edges;
    vector<pair<int,int>> adj[10];
    for(auto p : edges){
        int u = p [0];
        int v = p[1];
        int w = p[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    queue<pair<int,int>> q;
    vector<int> dist(10,1e9);
    q.push({0,0});
    while(!q.empty()){
        int node = q.front().first;
        int weight = q.front().second;
        q.pop();
        for(pair<int,int> p : adj[node]){
            int adjNode = p.first;
            int edgeweight = p.second;
            if(dist[node] + edgeweight < dist[adjNode]){
                dist[adjNode] = dist[node] + edgeweight;
            }

        }
    }
  
}