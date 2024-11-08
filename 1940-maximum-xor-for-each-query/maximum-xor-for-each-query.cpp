class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size(), Xorr = nums[0], maxXorr = pow(2,maximumBit)-1;
        for(int i = 1; i < n; i++){
            Xorr ^= nums[i];
        }
        vector<int>ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = Xorr ^ maxXorr;
            Xorr ^= nums[n-i-1];
        }
        return ans;
    }
};