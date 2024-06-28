class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>v(n,0);
        for(auto &it : roads){
            v[it[0]]++;
            v[it[1]]++;
        } 
        sort(v.begin(),v.end());
        long long ans = 0;
        for(long long i = 0; i < n; i++){
            ans += (i+1)*v[i];
        }
        return ans;
    }
};