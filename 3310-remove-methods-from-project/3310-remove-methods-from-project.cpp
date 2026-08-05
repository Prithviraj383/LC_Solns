class Solution {
public:

    void dfs(int source, vector<bool> &vis, vector<vector<int>> &adj){

        vis[source] = true;

        for(auto &it: adj[source]){
            
            if(!vis[it]) 
                dfs(it, vis, adj);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        //creating adj list
        vector<vector<int>> adj(n);
        for(auto it: invocations){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
        }

        vector<bool> vis(n, false);
        vector<int> ans, a1;

        dfs(k, vis, adj);

        for(auto it: invocations){
            int u = it[0], v = it[1];

            if(!vis[u] && vis[v]){
                for(int i=0;i<n;++i)
                    ans.push_back(i);
                return ans;
            }
        }

        for(int i=0;i<n;++i)
            if(!vis[i]) a1.push_back(i);

        return a1;
    }
};