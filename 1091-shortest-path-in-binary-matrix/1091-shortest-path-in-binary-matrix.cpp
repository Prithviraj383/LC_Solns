class Solution {
public:

    int isValid(int r, int c, int m){
        return (r>=0 && r<m) && (c>=0 && c<m);
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int m = grid.size();
        if(m==1) return grid[0][0] == 0 ? 1 : -1;

        //base case
        if(grid[0][0] == 1 || grid[m-1][m-1] == 1) return -1;

        vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        grid[0][0] = 1;

        while(!q.empty()){
            
            auto [cell, dist] = q.front();
            auto [r, c] = cell;
            q.pop();

            for(int i=0;i<8;++i){

                int nR = r+dr[i];
                int nC = c+dc[i];
                int nD = dist+1;

                if(isValid(nR, nC, m) && grid[nR][nC] == 0){
                    if(nR == m-1 && nC == m-1) return nD;
                    else {
                        q.push({{nR, nC}, nD});
                        grid[nR][nC] = 1;
                    }
                }
            }
        }
        return -1;
    }
};