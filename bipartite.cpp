#include<iostream>
#include<vector>
using namespace std;

//{ Driver Code Starts

// } Driver Code Ends
class Solution {
  public:
  
    bool bfs(vector<vector<int>>& adj,vector<int>& color,int parent){
        queue<int> q;
        q.push(parent);
        color[parent] = 0;
        while(!q.empty()){
            int nf = q.front();
            q.pop();
            for(int i : adj[nf]){
                if(color[i] == -1 ) {
                    color[i] = !color[nf];
                    q.push(i);
                    
                }
                else if(color[i] == color[nf]) return false;
                
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<int> color(V,-1);
        return bfs(adj,color,0);
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends