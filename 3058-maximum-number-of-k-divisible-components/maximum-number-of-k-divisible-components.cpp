class Solution {
public:
    int ans;
    vector<vector<int>>adj;
    vector<long long>sum;
    void dfs(int k, vector<int>&values, int u, int p){
        sum[u] = values[u];
        for(int i : adj[u]){
            if(i == p) continue;
            dfs(k, values, i, u);
            sum[u] += sum[i];
        }
        if(sum[u] % k == 0){
            ans++;
            sum[u] = 0;
        }
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.resize(n);
        sum.resize(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        ans = 0;
        dfs(k, values, 0, -1);
        return ans;
    }
};