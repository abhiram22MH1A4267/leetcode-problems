class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int grid[m][n];
        memset(grid, 0, sizeof(grid));

        for(auto it : guards){
            grid[it[0]][it[1]] = 2;
        }
        for(auto it : walls){
            grid[it[0]][it[1]] = 2;
        }
        int dirs[5] = {-1,0,1,0,-1};

        for(auto it : guards){
            for(int k = 0; k < 4; ++k){
                int x = it[0], y = it[1];
                int dx = dirs[k], dy = dirs[k+1];

                while(dx + x >= 0 && dx + x < m && dy + y >= 0 && dy + y < n && grid[dx + x][dy + y] < 2){
                    x += dx;
                    y += dy;
                    grid[x][y] = 1;
                } 
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            ans += count(grid[i], grid[i]+n, 0);
        }
        return ans;
    }
};