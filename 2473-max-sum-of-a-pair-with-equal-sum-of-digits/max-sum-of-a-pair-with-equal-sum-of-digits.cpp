class Solution {
public:
    int SumOfDigits(int n){
        int sum = 0;
        while(n != 0){
            int d = n%10;
            sum +=  d;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n = nums.size();
        for(int i : nums){
            int m = SumOfDigits(i);
            mp[m].push_back(i);
        }
        int ans = -1;
        for(auto it : mp){
            int n = it.second.size();
            if(n > 1){
                sort(it.second.begin(), it.second.end());
                ans = max(ans, it.second[n-1] + it.second[n-2]);
            }
        }
        return ans;
    }
};