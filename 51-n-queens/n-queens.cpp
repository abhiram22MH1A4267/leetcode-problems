class Solution {
public:
    vector<vector<string>>ans;
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
            string s = "";
            vector<string>chance;
            for(int i = 0; i < n; i++){
                s += '.';
            }
            for(int i = 0; i < n; i++){
                s[col[i]] = 'Q';
                chance.push_back(s);
                s[col[i]] = '.';
            }
            ans.push_back(chance);
            return;
        }
        for(int i = 0; i < n; i++){
            if(check(row,i)){
                col[row] = i;
                rec(row+1, n);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        col.clear();
        ans.clear();
        col.resize(n);
        rec(0,n);
        // for(auto &x : ans){
        //     for(auto &i : x) i++;
        // }
        return ans;
    }
};