class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>sub_arrays_sum;
        for(int i = 0; i < n; i++){
            int sub_sum = nums[i];
            sub_arrays_sum.push_back(sub_sum);
            for(int j = i+1; j < n; j++){
                sub_sum += nums[j];
                sub_arrays_sum.push_back(sub_sum);
            }
        }
        sort(sub_arrays_sum.begin(), sub_arrays_sum.end());
        int ans = 0;
        int modulo = 1e9+7;
        for(int i = left-1; i < right; i++){
            ans += sub_arrays_sum[i];
            ans %= modulo;
        }
        return ans;
    }
};