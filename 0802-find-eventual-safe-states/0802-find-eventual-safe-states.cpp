class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> indeg(n, 0);
        vector<vector<int>> rev(n);

        queue<int>  q;

        for(int i=0;i<n;++i){
            for(auto it: graph[i])
                rev[it].push_back(i);
        }

        for(int i=0;i<n;++i){
            for(auto it: rev[i])
                indeg[it]++;
        }

        for(int i=0;i<n;++i)
            cout << indeg[i] << endl;

        for(int i=0;i<n;++i)
            if(indeg[i]==0) q.push(i);


        vector<int> ans;
        while(!q.empty()){

            int v = q.front();
            q.pop();

            ans.push_back(v);

            for(auto it: rev[v]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;



        
    }
};