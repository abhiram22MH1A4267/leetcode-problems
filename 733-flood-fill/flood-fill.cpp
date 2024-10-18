class Solution {
public:
    void dfs(vector<vector<int>>&image, int row, int col, int color, int ini_Color, int dx[], int dy[], vector<vector<int>>&ans){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == ini_Color && ans[nrow][ncol] != color){
                dfs(image, nrow, ncol, color, ini_Color, dx, dy, ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini_Color = image[sr][sc];

        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        vector<vector<int>>ans = image;
        dfs(image, sr, sc, color, ini_Color, dx, dy, ans);
        return ans;
    }
};