class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int n = matrix.size(), m = matrix[0].size();
        int count = 0;
        int minVal = INT_MAX;
        bool zerofound = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                minVal = min(minVal, abs(matrix[i][j]));
                if(matrix[i][j] < 0){
                    ans += (long long) (abs(matrix[i][j]));
                    count++;
                }
                else if(matrix[i][j] == 0) zerofound = true;
                else ans += (long long) (matrix[i][j]);
            }
        }
        if((count & 1) == 0 || zerofound == true){
            return ans;
        }
        else{
            ans -= (long long) (2 * minVal);
            return ans;
        }
    }
};