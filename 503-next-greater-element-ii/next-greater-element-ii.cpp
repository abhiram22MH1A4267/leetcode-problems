class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int>ans(n, INT_MIN), vec;
        for(int i = n-1; i >= 0; i--){
            if(nums[n-1] < nums[i]){
                ans[n-1] = nums[i];
            }
            if(st.empty()) st.push(nums[i]);
            else if(st.top() > nums[i]){
                ans[i] = st.top();
                vec.push_back(st.top());
            }
            else{
                for(int j = vec.size() - 1; j >= 0; j--){
                    if(vec[j] > nums[i]){
                        ans[i] = vec[j];
                        break;
                    }
                }
            }
            st.push(nums[i]);
        }
        int maxi = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(nums[i] == maxi){
                ans[i] = -1;
                continue;
            }
            if(ans[i] == INT_MIN){
                for(int j = 0; j < i; j++){
                    if(nums[i] < nums[j]){
                        ans[i] = nums[j];
                        break;
                    }
                }
            }
        }
        return ans;
    }
};