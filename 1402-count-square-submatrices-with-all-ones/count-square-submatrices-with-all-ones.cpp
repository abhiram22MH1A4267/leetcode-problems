class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int ans = 0;
        ans = count(matrix[0].begin(), matrix[0].end(), 1);
        for(int i = 1; i < row; i++){
            ans += matrix[i][0];
        }
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][j] == 0) continue;
                matrix[i][j] = 1 + min({matrix[i-1][j], matrix[i-1][j-1], matrix[i][j-1]});
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};