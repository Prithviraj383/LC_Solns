class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //creating adj list
        vector<vector<int>> adj[n+1];
        for(auto it: times){
            int u = it[0], v = it[1], wt = it[2];

            adj[u].push_back({v, wt});
        }

        vector<int> dis(n+1, 1e9);
        dis[k] = 0;
        
        set<pair<int, int>> st;
        st.insert({0, k});

        while(!st.empty()){
            auto it = *(st.begin());
            int distance = it.first;
            int node = it.second;
            st.erase(it);

            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeW = it[1];

                if(distance + edgeW < dis[adjNode]){
                    if(dis[adjNode] != 1e9) 
                        st.erase({dis[adjNode], adjNode});

                    dis[adjNode] = distance + edgeW;
                    st.insert({dis[adjNode], adjNode});
                }
            }
        }

        int ans=INT_MIN;
        for(int i=1;i<=n;++i){
            int val = dis[i];
            if(val == 1e9) return -1;
            if(val > ans) ans = val;
        }
        
        return ans;
    }
};