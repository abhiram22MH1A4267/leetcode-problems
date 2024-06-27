class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        int n = edges.size();
        int m = edges[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mp[edges[i][j]]++;
            }
        }
        int ans = 0;
        for(auto it : mp){
            if(it.second == n){
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};