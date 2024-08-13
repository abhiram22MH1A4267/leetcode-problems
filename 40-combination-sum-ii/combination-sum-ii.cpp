class Solution {
    vector<vector<int>>v;
    void fun(vector<int>c,int start,int end,int target,int sum,vector<int>ans){
        if(start >= end and sum!=target){
            return;
        }
        if(sum == target){
            v.push_back(ans);
            return;
        }
        else if(sum > target){
            return;
        }
        ans.push_back(c[start]);
        fun(c,start+1,end,target,sum+c[start],ans);
        while(start+1 < end && c[start] == c[start+1]) start++;
        ans.pop_back();
        fun(c,start+1,end,target,sum,ans);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        fun(candidates,0,candidates.size(),target,0,{});
        //v.erase(unique(v.begin(),v.end()),v.end());
        return v;
    }
};