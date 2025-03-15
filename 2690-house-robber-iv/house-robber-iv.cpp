class Solution {
public:
    bool CanRobK(vector<int>&nums, int k, int capability){
        int count = 0, i = 0;
        while(i < nums.size()){
            if(nums[i] <= capability){
                count++;
                i += 2;
            }
            else{
                i++;
            }
        }
        return count >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        while(mini < maxi){
            int mid = mini + (maxi - mini) / 2;
            if(CanRobK(nums, k, mid)){
                maxi = mid;
            }
            else{
                mini = mid + 1;
            }
        }
        return mini;
    }
};