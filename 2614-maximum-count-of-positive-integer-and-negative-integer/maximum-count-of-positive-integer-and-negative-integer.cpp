class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int ans = 0, mini = 0, maxi = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < 0) mini++;
            if(nums[i] > 0){
                maxi = n-i;
                break;
            }
        }
        return max(maxi, mini);
    }
};