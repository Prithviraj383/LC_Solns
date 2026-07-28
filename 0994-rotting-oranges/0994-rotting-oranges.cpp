class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};

        queue<pair<int, int>> q;
        int total=0, time=0, cnt=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){

                if(grid[i][j] != 0) total++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        while(!q.empty()){
            
            int lvlSize = q.size();
            cnt += lvlSize;

            while(lvlSize--){
                auto [r, c] = q.front();
                q.pop();

                for(int i=0;i<4;++i){
                    int nr = r+dr[i];
                    int nc = c+dc[i];

                    if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc] == 1){
                        vis[nr][nc] = true;
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }

            if(!q.empty()) time++;
        }

        if(cnt == total) return time;
        return -1;
    }
};