#include<iostream>
#include<queue>
using namespace std;


int shortestPath(vector<pair<int,int>> adj[],int source,int destination,int k,int V){

    queue<pair<int,pair<int,int>>> q;
    vector<int> dist(V,0);
    q.push({0,{source,0}});
    while(!q.empty()){
        pair<int,pair<int,int>> pair = q.front();
        int stops = pair.first;
        int node = pair.second.first;
        int weight = pair.second.second;
        q.pop();
        for(auto p : adj[node]){
            int adjacentNode = p.second;
            int edgeWeight = p.first;
            if(weight + edgeWeight < dist[adjacentNode]  && stops <= k){
                 dist[adjacentNode] = weight + edgeWeight;
                 q.push({stops+1,{adjacentNode,weight+edgeWeight}});
            }
        }
    }

}


int main(){

}

