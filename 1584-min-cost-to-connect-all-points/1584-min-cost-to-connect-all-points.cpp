class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        int sum=0;
        vector<int> vis(n, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        //{wt, node};
        pq.push({0, 0});
        unordered_map<int, int> cache;

        while(!pq.empty()){

            auto [wt, node] = pq.top();
            pq.pop();

            if(vis[node]) continue;
            vis[node] = 1;
            sum += wt;

            for(int i=0;i<n;++i){

                if(!vis[i]){
                    int dist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    if(cache.find(i) == cache.end() || dist < cache[i]){
                        pq.push({dist, i});
                    }
                }
            }
        }

        return sum;
    }
};