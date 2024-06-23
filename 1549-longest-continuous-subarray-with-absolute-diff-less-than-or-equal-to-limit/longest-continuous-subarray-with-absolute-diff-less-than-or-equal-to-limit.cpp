class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>decq;
        deque<int>incq;
        int ans = 0, i = 0;
        for(int j = 0; j < nums.size(); ++j){
            int num = nums[j];
            while(!decq.empty() && num > decq.back()){
                decq.pop_back();
            }
            decq.push_back(num);
            while(!incq.empty() && num < incq.back()){
                incq.pop_back();
            }
            incq.push_back(num);
            while(decq.front() - incq.front() > limit){
                if(decq.front() == nums[i]){
                    decq.pop_front();
                }
                if(incq.front() == nums[i]){
                    incq.pop_front();
                }
                ++i;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};