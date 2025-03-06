class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int i = 0, j = 0, flag = 0;
        vector<int>ans;
        while(ans.size() < (n*m)){
            while(i >= 0 && j < m){
                ans.push_back(mat[i][j]);
                i--;
                j++;
            }
            if(j >= m){
                j--;
                i += 2;
            }
            if(i < 0){
                i = 0;
            }
            while(j >= 0 && i < n){
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
            if(i >= n){
                i--;
                j += 2;
            }
            if(j < 0){
                j = 0;
            }
        }
        return ans;
    }
};