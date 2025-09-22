class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i : nums){
            mp[i]++;
        }

        int ans = 0, freq = 0;
        for(auto it : mp){
            if(it.second > freq){
                ans = it.second;
                freq = it.second;
            }
            else if(it.second == freq){
                ans += it.second;
            }
        }

        return ans;
    }
};