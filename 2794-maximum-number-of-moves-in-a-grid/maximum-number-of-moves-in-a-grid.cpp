class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<int>dp(n);
        for(int j = 1; j < m; ++j){
            int leftTop = 0;
            bool found = false;
            for(int i = 0; i < n; ++i){
                int curr = -1;
                int nextLeftTop = dp[i];
                if(i-1 >= 0 && leftTop != -1 && grid[i][j] > grid[i-1][j-1]){
                    curr = max(curr, leftTop+1);
                }
                if(dp[i] != -1 && grid[i][j] > grid[i][j-1]){
                    curr = max(curr, dp[i]+1);
                }
                if(i+1 < n && dp[i+1] != -1 && grid[i][j] > grid[i+1][j-1]){
                    curr = max(curr, dp[i+1]+1);
                }
                dp[i] = curr;
                found = found || (dp[i] != -1);
                leftTop = nextLeftTop;
            }
            if(!found) break;
            ans = j;
        }
        return ans;
    }
};