#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// space complexity -> 
void dfs(int node,vector<int> adj[],vector<int> vis,vector<int>& ans){
    vis[node] = 1;
    ans.push_back(node);
    for(auto k : adj[node]){
        if(!vis[k]){

        dfs(k,adj,vis,ans);
        }
    }

}
int main(){
    int V;
    vector<int> adj[V+1];
    vector<int> ans;
    vector<int> vis(V+1,0);
    dfs(0,adj,vis,ans);

}