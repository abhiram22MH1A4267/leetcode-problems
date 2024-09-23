class Solution {
public:
    int fun(string &s, unordered_set<string>&st, int i, vector<int>&dp){
        if(i == s.size()) return 0;

        if(dp[i] != -1) return dp[i];

        string str = "";
        int n = s.size();
        for(int j = i; j < s.size(); j++){
            str += s[j];
            int v = str.size();
            if(st.count(str)){
                v = 0;
            }
            n = min(n, v + fun(s,st,j+1,dp));
        }
        return dp[i] = n;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int>dp(51,-1);
        unordered_set<string>st;
        for(string &x : dictionary){
            st.insert(x);
        }
        return fun(s,st,0,dp);
    }
};