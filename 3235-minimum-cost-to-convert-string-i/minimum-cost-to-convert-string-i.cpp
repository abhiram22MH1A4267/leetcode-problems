class Solution {
public:
    int dp[26][26];
    inline void fun(vector<char>&original, vector<char>&changed, vector<int>&cost){
        fill(&dp[0][0], &dp[0][0]+26*26, INT_MAX);
        int original_size = original.size();
        for(int i = 0; i < original_size; i++){
            int row = original[i]-'a';
            int col = changed[i]-'a';
            dp[row][col] = min(dp[row][col], cost[i]);
        }
        for(int i = 0; i < 26; i++) dp[i][i] = 0;
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    dp[i][j] = min((long long)dp[i][j], (long long)dp[i][k]+dp[k][j]);
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        fun(original, changed, cost);
        int n = source.size();
        long long ans = 0;
        for(int i = 0; i < n; i++){
            int row = source[i]-'a';
            int col = target[i]-'a';
            if(dp[row][col] == INT_MAX) return -1;
            ans += dp[row][col];
        }
        return ans;
    }
};