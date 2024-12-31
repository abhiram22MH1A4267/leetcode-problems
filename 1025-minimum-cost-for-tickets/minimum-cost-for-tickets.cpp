class Solution {
public:
    int dp[366];
    bitset<366>need = 0;
    int fun(int d, int d0, vector<int>&costs){
        if(d < 0) return 0;
        if(!need[d]) return fun(d-1, d0, costs);
        if(dp[d] != -1) return dp[d];
        return dp[d] = min({costs[0] + fun(d-1, d0, costs),
        costs[1] + fun(d-7, d0, costs),
        costs[2] + fun(d-30, d0, costs),
        });
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        for(int i : days){
            need[i] = 1;
        }
        return fun(days.back(), days[0], costs);
    }
};