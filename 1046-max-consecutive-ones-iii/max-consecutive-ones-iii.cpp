class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0, left = 0, max_Count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) count++;
            while(count > k){
                if(nums[left] == 0) count--;
                left++;
            }
            max_Count = max(max_Count, (i-left+1));
        }
        return max_Count;
    }
};