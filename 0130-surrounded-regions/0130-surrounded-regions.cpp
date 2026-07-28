class Solution {
public:

    bool boundary(int r, int c, int m, int n){
        return r==0 || r==m-1 || c==0 || c==n-1;
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};

        queue<pair<int, int>> q;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(boundary(i, j, m, n) && board[i][j] == 'O'){
                    vis[i][j] = true;
                    q.push({i, j}); 
                }
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int i=0;i<4;++i){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc] == 'O'){
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};