class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans, arr1, arr2;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < pivot){
                ans.push_back(nums[i]);
            }
            else if(nums[i] == pivot){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }
        for(int i : arr1){
            ans.push_back(i);
        }
        for(int i : arr2){
            ans.push_back(i);
        }
        return ans;
    }
};