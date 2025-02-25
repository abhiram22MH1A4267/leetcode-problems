class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        bool sum_is_odd = 0;
        int count[2] = {1,0};
        long long ans = 0;
        for(int i : arr){
            sum_is_odd ^= (i & 1);
            ans += count[1-sum_is_odd];
            count[sum_is_odd]++;
        }
        return ans%mod;
    }
};