class Solution {
public:
    int d[5] = {0, 1, 0, -1, 0};
    int dfs(int i, int j, vector<vector<int>>&grid){
        int n = grid.size(), m = grid[0].size();
        int fish = grid[i][j];
        grid[i][j] = 0;
        for(int a = 0; a < 4; a++){
            int row = i+d[a], col = j + d[a+1];
            if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0) continue;
            fish += dfs(row, col, grid);
        }
        return fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    ans = max(ans, dfs(i,j, grid));
                }
            }
        }
        return ans;
    }
};