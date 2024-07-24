class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>mappedIntegerPairs(n);

        for(int i = 0; i < n; ++i){
            int currValue = nums[i];
            int mappedNum = currValue == 0? mapping[0] : 0;
            int placeValue = 1;
            while(currValue > 0){
                int digit = currValue % 10;
                mappedNum += placeValue * mapping[digit];
                currValue /= 10;
                placeValue *= 10;
            }
            mappedIntegerPairs[i] = {mappedNum,i};
        }
        sort(mappedIntegerPairs.begin(), mappedIntegerPairs.end());
        vector<int>ans;
        for(auto it : mappedIntegerPairs){
            ans.push_back(nums[it.second]);
        }
        return ans;
    }
};