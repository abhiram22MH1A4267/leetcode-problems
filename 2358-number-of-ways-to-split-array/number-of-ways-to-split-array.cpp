class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total_sum = 0;
        int n = nums.size();
        for(int i : nums){
            total_sum += i;
        }
        long long left_sum = 0;
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            left_sum += nums[i];
            total_sum -= nums[i];
            if(left_sum >= total_sum) ans++;
        }
        return ans;
    }
};