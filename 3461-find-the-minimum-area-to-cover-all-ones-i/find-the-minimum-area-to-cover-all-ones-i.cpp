class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int top = n-1, bottom = 0, left = m-1, right = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    top = min(top, i);
                    left = min(left, j);
                    right = max(right, j);
                    bottom = max(bottom, i);
                }
            }
        }

        int length = right - left + 1;
        int height = bottom - top + 1;

        return length * height;
    }
};