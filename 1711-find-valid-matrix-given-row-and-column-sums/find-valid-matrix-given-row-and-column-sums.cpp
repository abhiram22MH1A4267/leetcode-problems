class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int n = rowSum.size(), m = colSum.size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i = 0, j= 0; i < n && j < m; i+=(rowSum[i] == 0), j+=(colSum[j] == 0)){
            int x = min(rowSum[i],colSum[j]);
            ans[i][j] = x;
            rowSum[i] -= x;
            colSum[j] -= x;
        }
        return ans;
    }
};