class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> losses(n);
        
        for (const auto& edge : edges) {
            losses[edge[1]]++;
        }
        
        int champion = -1;
        for (int i = 0; i < n; i++) {
            if (losses[i] == 0) {
                if (champion != -1) return -1;
                champion = i;
            }
        }
        
        return champion;
    }
};