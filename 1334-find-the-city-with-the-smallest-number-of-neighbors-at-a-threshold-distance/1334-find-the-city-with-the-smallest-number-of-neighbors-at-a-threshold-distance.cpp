class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for(int i=0;i<n;++i){
            mat[i][i] = 0;
        }

        for(auto it: edges){
            int u = it[0], v = it[1], wt = it[2];

            mat[u][v] = wt;
            mat[v][u] = wt;
        }

        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    if(mat[i][k] != 1e9 && mat[j][j]!=1e9&&mat[i][k] + mat[k][j] < mat[i][j]) {
                        mat[i][j] = mat[i][k] + mat[k][j];
                    }
                }
            }
        }

        int mini = INT_MAX;
        int res = 0;
        for(int i=0;i<n;++i){
            int cnt=0;
            for(int j=0;j<n;++j){
                if(mat[i][j] <= distanceThreshold) cnt++;
            }

            if(cnt <= mini){
                mini = cnt;
                res = i;
            }
        }

        return res;

        return mini;
    }
};