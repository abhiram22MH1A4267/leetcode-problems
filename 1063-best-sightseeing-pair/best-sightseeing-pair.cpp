class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = INT_MIN, maxi = values[0], n = values.size();
        for(int i = 1; i < n; i++){
            ans = max(ans, maxi+values[i]-i);
            maxi = max(maxi, values[i]+i);
        }
        return ans;
    }
};