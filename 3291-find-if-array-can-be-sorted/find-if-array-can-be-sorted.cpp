class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>bitCount(n,0);
        for(int i = 0; i < n; i++){
            bitCount[i] = __builtin_popcount(nums[i]);
        }
        int preMax = 0, currMax, currMin;
        for(int i = 0; i < n; i++){
            currMax = nums[i];
            currMin = nums[i];
            while(i+1 < n && bitCount[i] == bitCount[i+1]){
                currMax = max(currMax, nums[i+1]);
                currMin = min(currMin, nums[i+1]);
                i++;
            }
            if(currMin >= preMax) preMax = currMax;
            else return false;
        }
        return true;
    }
};