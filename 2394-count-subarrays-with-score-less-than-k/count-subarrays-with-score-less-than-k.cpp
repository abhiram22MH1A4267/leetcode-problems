class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int start = 0, n = nums.size();
        long long sum = 0, count = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            while(sum * (i - start + 1) >= k){
                sum -= nums[start];
                start++;
            }
            count += i - start + 1;
        }
        return count;
    }
};