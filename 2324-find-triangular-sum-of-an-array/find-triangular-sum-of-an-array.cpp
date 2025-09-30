class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n > 1){
            vector<int>arr;
            for(int i = 1; i < n; i++){
                int val = (nums[i] + nums[i-1]) % 10;
                arr.push_back(val);
            }
            nums = arr;
            n--;
        }
        return nums[0];
    }
};