class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_ele = max_element(nums.begin(), nums.end())-nums.begin();
        int max_length = 0, x = nums[max_ele];
        for(int i = max_ele; i < n; i++){
            int len = 0;
            while(i < n && nums[i] == x){
                i++;
                len++;
            }
            max_length = max(max_length, len);
        }
        return max_length;
    }
};