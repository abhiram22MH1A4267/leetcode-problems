class Solution {
public:
    int count, n;
    vector<int>v;
    int find(int x) {
        if (x != v[x]) {
            v[x] = find(v[x]);
        }
        return v[x];
    }
    int g(int i, int j, int k) {
        return (i * n + j) * 4 + k;
    }
    void uni(int x, int y) {
        x = find(x); y = find(y);
        if (x != y) {
            v[x] = y;
            count--;
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        count = n*n*4;
        for(int i = 0; i < n*n*4; ++i){
            v.push_back(i);
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i > 0) uni(g(i-1, j, 2), g(i, j, 0));
                if(j > 0) uni(g(i, j-1, 1), g(i, j, 3));
                if(grid[i][j] != '/'){
                    uni(g(i, j, 0), g(i, j, 1));
                    uni(g(i, j, 2), g(i, j, 3));
                }
                if(grid[i][j] != '\\'){
                    uni(g(i, j, 0), g(i, j, 3));
                    uni(g(i, j, 2), g(i, j, 1));
                }
            }
        }
        return count;
    }
};