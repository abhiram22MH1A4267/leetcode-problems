class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxPrefix = 0, minPrefix = 0, prevMax = 0, prevMin = 0;
        for(int i : nums){
            prevMax = max(prevMax + i, i);
            prevMin = min(prevMin + i, i);
            maxPrefix = max(maxPrefix, prevMax);
            minPrefix = min(minPrefix, prevMin);
        }
        return max(abs(maxPrefix), abs(minPrefix));
    }
};