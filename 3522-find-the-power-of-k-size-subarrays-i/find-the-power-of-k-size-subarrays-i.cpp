class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i <= n-k; i++){
            int flag = 0, max_element = nums[i];
            for(int j = i; j < i+k-1; j++){
                max_element = max(max_element, nums[j+1]);
                if(nums[j]+1 != nums[j+1]){
                    ans.push_back(-1);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                ans.push_back(max_element);
            }
        }
        return ans;
    }
};