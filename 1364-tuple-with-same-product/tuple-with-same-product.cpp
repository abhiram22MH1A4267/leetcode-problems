class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                int product = nums[i] * nums[j];
                ans += mp[product] * 8;
                mp[product]++;
            }
        }
        return ans;
    }
};