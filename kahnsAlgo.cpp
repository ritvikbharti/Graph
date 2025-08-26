#include<iostream>
#include<vector>
#include<queue> 
using namespace std;



int main(){
    vector<int> adj[] = {};
    vector<vector<int>> edges = {};
    int n = 0;
    vector<int> inDegree(n,0);
    for(auto pair : edges){
        int u = pair[0];
        int v = pair[1];
        adj[u].push_back(v);
        inDegree[v]++;

    }
    vector<int> ans;
    queue<int> q;

    for(int i = 0;i<n;i++){
        if(inDegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int frontNode = q.front();
        ans.push_back(frontNode);
        q.pop();
        for(int adjNode : adj[frontNode] ){
            inDegree[adjNode]--;
            if(!inDegree[adjNode] ) q.push(adjNode);
        }
    }


}