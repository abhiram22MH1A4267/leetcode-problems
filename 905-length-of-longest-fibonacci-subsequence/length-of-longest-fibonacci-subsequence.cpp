class Solution {
public:
    int dp[1000][1000];
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>mp;
        mp.reserve(n);
        fill(&dp[0][0], &dp[0][0] + n*1000, 2);
        int ans = 0;

        for(int i = 0; i < n; i++){
            mp[arr[i]] = i;
        }

        for(int i = 1; i < n-1; i++){
            int f1 = arr[i];
            for(int j = i+1; j < n; j++){
                int f2 = arr[j];
                int f = f2 - f1;
                if(f >= f1) break;
                if(mp.count(f)){
                    int k = mp[f];
                    dp[i][j] = dp[k][i] + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans > 2 ? ans : 0;
    }
};