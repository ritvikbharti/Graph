//{ Driver Code Starts
// Initial Template for C++

#include <iostream>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {

  public:
    void dfs(int node,vector<pair<int,int>> adj[],vector<int>& vis,stack<int> &st){
        vis[node] = 1;
        
        for(auto pair : adj[node]){
            int it = pair.first;
            if(!vis[it]) dfs(it,adj,vis,st);
        }
        
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        vector<pair<int,int>> adj[V];
        stack<int> st;
        vector<int> vis(V,0);
        for(int i =0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        for(int i =0;i<V;i++){
            if(!vis[i]) dfs(i,adj,vis,st);
        }
        vector<int> ans(V,INT_MAX);
        ans[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto pair : adj[node]){
                int it = pair.first;
                int wt = pair.second;
                if(ans[node] != INT_MAX && ans[node] + wt < ans[it]){
                    ans[it] = ans[node] + wt;
                }
                
                
            }
        }
        int cn = 0;
        for(int i : ans){
            if(i == INT_MAX){
                ans[cn] = -1;
            }
            cn++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends