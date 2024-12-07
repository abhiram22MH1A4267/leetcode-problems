class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while(l < r){
            int m = l + (r-l) / 2;
            long long count = 0;
            for(int i = 0; i < n && count <= maxOperations; i++){
                count += (nums[i] - 1) / m;
            }
            if(count <= maxOperations) r = m;
            else l = m+1;
        }
        return r;
    }
};