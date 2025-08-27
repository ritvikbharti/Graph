#include<iostream>
#include<vector>
#include<queue>
using namespace std;



int main(){
    int n;
    vector<vector<int>> edges;
    vector<pair<int,int>> adj[n];
    for(auto p : edges){
        int u = p[0];
        int v = p[1];
        int w = p[2];
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n,1e9);
    pq.push({0,0});
    while(!pq.empty()){
        int frontNode= pq.top().first;

        pq.pop();
        for(pair<int,int> p : adj[frontNode]){
            int adjacentNode = p.first;
            int edgeWeight = p.second;
            if(dist[frontNode] + edgeWeight < dist[adjacentNode]){
                dist[adjacentNode] = dist[frontNode] + edgeWeight;
            }
        }

    }
}