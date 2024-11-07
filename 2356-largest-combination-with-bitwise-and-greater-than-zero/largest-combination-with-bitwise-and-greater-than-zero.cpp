class Solution {
public:
    void find(int n, vector<int>&ans){
        int j = 31;
        while(n > 0){
            int a = (n&1);
            ans[j] += a;
            n >>= 1;
            j--;
        }
    }
    int largestCombination(vector<int>& candidates) {
        vector<int>ans(32,0);
        for(int i : candidates){
            find(i,ans);
        }
        int res = 0;
        for(int i : ans){
            res = max(res, i);
        }
        return res;
    }
};