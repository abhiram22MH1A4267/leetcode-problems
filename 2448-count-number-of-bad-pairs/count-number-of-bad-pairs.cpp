class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long goodpairs = 0, n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++){
            int k = nums[i] - i;
            goodpairs += mp[k];
            mp[k]++;
        }
        return (n*(n-1) / 2) - goodpairs;
    }
};