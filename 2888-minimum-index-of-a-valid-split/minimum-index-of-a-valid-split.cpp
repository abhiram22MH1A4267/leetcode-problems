class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<unsigned,unsigned>mp;
        mp.reserve(n);
        int maxi = 1, count = 0;
        for(int i : nums){
            unsigned& f = mp[i];
            if(++f > (n/2)){
                maxi = f;
                count = i;
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += (nums[i] == count);
            if((ans * 2) > (i+1) && ((maxi - ans) * 2) > (n-i-1)){
                return i;
            }
        }
        return -1;
    }
};