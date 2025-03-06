class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int>mp;
        for(auto i : grid){
            for(int j : i){
                mp[j]++;
            }
        }
        int val = 1, rep = 0, mis = 0;
        for(auto it : mp){
            if(it.first != val){ 
                mis = val;
                val++;
            }
            if(it.second > 1){
                rep = val;
            }
            if(rep != 0 && mis != 0){
                return {rep, mis};
            }
            val++;
        }
        return {rep, val};
    }
};