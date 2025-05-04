class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int>mp;
        for(auto it : dominoes){
            int a = min(it[0], it[1]);
            int b = max(it[0], it[1]);
            int val = a * 10 + b;
            mp[val]++;
        }
        int ans = 0;
        for(auto it : mp){
            if(it.second > 1) ans += (it.second * (it.second - 1))/2; 
        }
        return ans;
    }
};