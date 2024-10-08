class Solution {
public:
    bool fun(int i, int j, string &s, string &p, vector<vector<int>>&dp){
        if(i < 0 || j < 0){
            if(i >= 0 || j >= 0) return false;
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = fun(i-1, j-1, s, p, dp);
        }
        else if(p[j] == '*'){
            return dp[i][j] = fun(i-1, j, s, p, dp) || fun(i-1, j-1, s, p, dp) || fun(i, j-1, s, p, dp);
        }
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        s = '2' + s;
        p = '2' + p;
        int n = s.size(), m = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(n-1,m-1,s,p,dp);
    }
};