class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int>mp;
        for(auto i : matrix){
            string pattern;
            if(i[0] == 0){
                for(int j : i){
                    pattern += to_string(j);
                }
            }
            else{
                for(int j : i){
                    pattern += to_string(j ^ 1);
                }
            }
            mp[pattern]++;
        }
        int ans = 0;
        for(auto it : mp){
            ans = max(ans, it.second);
        }
        return ans;
    }
};