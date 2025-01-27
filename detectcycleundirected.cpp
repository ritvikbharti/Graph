//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathVis,int node){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(int i : adj[node]){
            if(!vis[i] ){
               if(dfs(adj,vis,pathVis,i) == true) return true;
            }
            if( pathVis[i]) return true;
        }
        pathVis[node] = 0;
        
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        
        for(int i =0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,vis,pathVis,i) == true) return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends