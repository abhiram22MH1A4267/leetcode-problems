class Solution {
public:
    bool isMagic(vector<vector<int>>&grid, int rowstart, int colstart){
        vector<int>nums;
        for(int i = rowstart; i < rowstart+3; i++){
            for(int j = colstart; j < colstart+3; j++){
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < 9; i++){
            if(nums[i] != i+1) return false;
        }
        int sum = grid[rowstart][colstart] + grid[rowstart][colstart+1] + grid[rowstart][colstart+2];

        for(int i = rowstart; i < rowstart+3; i++){
            if(grid[i][colstart] + grid[i][colstart+1] + grid[i][colstart+2] != sum){
                return false;
            }
        }

        for(int i = colstart; i < colstart+3; i++){
            if(grid[rowstart][i] + grid[rowstart+1][i] + grid[rowstart+2][i] != sum){
                return false;
            }
        }

        if(grid[rowstart][colstart] + grid[rowstart+1][colstart+1] + grid[rowstart+2][colstart+2] != sum){
            return false;
        }
        if(grid[rowstart][colstart+2] + grid[rowstart+1][colstart+1] + grid[rowstart+2][colstart] != sum){
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int rows = grid.size();
        int col = grid[0].size();

        for(int i = 0; i <= rows-3; i++){
            for(int j = 0; j <= col-3; j++){
                if(isMagic(grid, i ,j)){
                    count++;
                }
            }
        }
        return count;
    }
};