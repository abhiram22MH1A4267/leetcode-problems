class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        vector<vector<int>>dis(n, vector<int>(m,0));
        queue<pair<pair<int,int>, int>>q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[row][col] = steps;

            for(int i = 0; i < 4; i++){
                int nrow = row + dx[i], ncol = col + dy[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;

                    q.push({{nrow, ncol}, steps+1});
                }
            }
        }
        return dis;
    }
};