class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        k = min(k, n);
        for(int i = 0; i < k; i++){
            if(mp.find(nums[i]) != mp.end()) return true;
            mp[nums[i]] = 1;
        }
        int i = 0;
        for(int j = k; j < n; j++){
            if(mp.find(nums[j]) != mp.end()) return true;
            mp[nums[j]] = 1;
            mp.erase(nums[i]);
            i++;
        }
        return false;
    }
};