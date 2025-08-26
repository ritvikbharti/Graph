#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void topoSort(vector<pair<int,int>> adj[],vector<int>& dist,vector<int>& vis,stack<int>& st,int node){
    vis[node] =1;
    for(pair<int,int> pair : adj[node]){
        int adjNode= pair.first;
        if(!vis[adjNode]) topoSort(adj,dist,vis,st,adjNode);

    }

    st.push(node);
}
int main(){
    vector<vector<int>> edges;
    vector<pair<int,int>> adj[5];
    for(auto pair : edges){
        int u = pair[0];
        int v = pair[1];
        int w = pair[2];
        adj[u].push_back({v,w});

    }
    vector<int> dist(edges.size(),1e9);
    stack<int> st;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(pair<int,int> pair : adj[node]){
            int adjNode = pair.first;
            int weight = pair.second;

            if(dist[node] + weight < dist[adjNode]){
                dist[adjNode] = dist[node] + weight;
            }
        }
    }
    

}