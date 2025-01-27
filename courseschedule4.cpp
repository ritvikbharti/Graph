class Solution {
public:
    void dfs(vector<int> adj[],int node,stack<int>& st,vector<int> &vis){
        vis[node] =1;
        

        for(int i : adj[node]){
            if(!vis[i]){

            dfs(adj,i,st,vis);
            }
        }

        st.push(node);
       


    }
    void bfs(int node,vector<int> adj[],vector<int> vis,vector<vector<int>>& ans){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int fr = q.front();
            q.pop();
            for(int i : adj[fr]){
                if(!vis[i]){
                    // cout << fr <<" " << i << endl;
                    ans[node][i] = 1;
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }

    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // vector<int> pathVis(numCourses,0);
        // stack<int> st;
        
        
        
        vector<int> adj[numCourses];
        for(int i = 0;i <prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            
        }
        vector<int> vis(numCourses,0);
        vector<vector<int>> ans(numCourses,vector<int> (numCourses,0));
        for(int i = 0;i<numCourses;i++){
            bfs(i,adj,vis,ans);
        }

        for(int i =0;i<ans.size();i++){
            for(int j =0;j<ans[0].size();j++){
                cout <<ans[i][j] <<" ";
            }
            cout << endl;
        }
        return {};



    }
};