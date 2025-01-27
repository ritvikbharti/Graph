#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int V;
    vector<int> adj[V+1];
     int vis[V] = {0};
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        vector<int> bfs;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            bfs.push_back(f);
            for(int i : adj[f]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }

}
