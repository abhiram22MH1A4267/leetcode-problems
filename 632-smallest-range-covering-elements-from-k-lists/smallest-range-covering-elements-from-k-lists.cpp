class Solution {
public:
    bool less(pair<int,int>&x, pair<int,int>&y){
        auto [a,b] = x;
        auto [c,d] = y;
        if(b-a == d-c) return a < c;
        return b-a < d-c;
    }
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int,int>>A;
        for(int i = 0; i < n; i++){
            for(int j : nums[i]){
                A.emplace_back(j,i);
            }
        }
        sort(A.begin(), A.end());
        int length = A.size(), count = 0;
        vector<int>freq(n,0);
        pair<int,int> min_range = {0,INT_MAX};
        for(int l = 0, r = 0; r < length; r++){
            int fR = ++freq[A[r].second];
            if(fR == 1) count++;
            while(count == n){
                pair<int,int> range = {A[l].first, A[r].first};
                if(less(range, min_range)) min_range = range;
                int fL = --freq[A[l].second];
                if(fL == 0) count--;
                l++;
            }
        }
        return {min_range.first, min_range.second};
    }
};