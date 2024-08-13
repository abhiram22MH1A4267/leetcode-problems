class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>dp(3,0);
        for(int num : nums){
            vector<int>temp(dp);
            for(int sum : temp){
                int newsum = sum+num;
                int remainder = newsum % 3;
                dp[remainder] = max(dp[remainder], newsum);
            }
        }
        return dp[0];
    }
};