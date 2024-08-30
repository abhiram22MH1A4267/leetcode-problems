class Solution {
public:
    int ans = 0;
    vector<int>col;
    bool check(int row, int i){
        for(int j = 0; j < row; j++){
            if(col[j] == i) return 0;
            if(abs(j-row) == abs(col[j]-i)) return 0;
        }
        return 1;
    }
    void rec(int row, int n){
        if(row == n){
            ans++;
            return;
        }
        for(int i = 0; i < n; i++){
            if(check(row,i)){
                col[row] = i;
                rec(row+1,n);
            }
        }
    }
    int totalNQueens(int n) {
        col.clear();
        ans = 0;
        col.resize(n);
        rec(0,n);
        return ans;
    }
};