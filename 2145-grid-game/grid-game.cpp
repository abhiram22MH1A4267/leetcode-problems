class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long>topPrefix(n+1,0) , bottomPrefix(n+1,0);

        for(int i = 0; i < n; i++){
            topPrefix[i+1] = topPrefix[i] + grid[0][i];
            bottomPrefix[i+1] = bottomPrefix[i] + grid[1][i];
        }
        long long result = LLONG_MAX;
        for(int i = 0; i < n; i++){
            long long top_remain = topPrefix[n] - topPrefix[i+1];
            long long bottom_remain = bottomPrefix[i];

            long long player_score = max(top_remain, bottom_remain);
            result = min(result, player_score);
        }
        return result;
    }
};