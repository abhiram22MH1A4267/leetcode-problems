class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size(), start = -1, end = -1;
        long long int res = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0) {
                start = end = i;
                continue;
            }

            res += i - start;
        }

        return res;
    }
};