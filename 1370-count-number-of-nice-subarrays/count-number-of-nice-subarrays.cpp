class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>total_count(n+1,0);
        total_count[0] = 1;
        int count = 0, ans = 0;
        for(int i : nums){
            count += (i&1);
            if(count - k >= 0) ans += total_count[count-k];
            total_count[count]++;
        }
        return ans;
    }
};