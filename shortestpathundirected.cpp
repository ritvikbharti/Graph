//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V = adj.size();
        
        vector<int> ans(V,INT_MAX);
        queue<int> q;
        q.push(src);
        ans[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i : adj[node]){
                if(ans[node]!= INT_MAX && ans[node] + 1 < ans[i] ){
                    ans[i] = ans[node] +1;
                    q.push(i);
                }
            }
            
        }
        for(int i =0;i<ans.size();i++){
            if(ans[i]==INT_MAX) ans[i] =-1;
        }
        
        return ans;
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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends