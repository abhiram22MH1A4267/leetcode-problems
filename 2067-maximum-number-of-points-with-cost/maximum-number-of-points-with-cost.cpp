class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        long long currmax = 0;
        vector<long long> maxpoints(n), rightrow(n);
        for(auto row : points){
            currmax = 0;
            for(int j = n-1; j >= 0; j--){
                currmax = max(currmax, maxpoints[j]);
                rightrow[j] = currmax--;
            }
            currmax = 0;
            for(int j = 0; j < n; j++){
                currmax = max(currmax, maxpoints[j]);
                maxpoints[j] = max(currmax-- , rightrow[j])+row[j];
            }
        }
        return *max_element(maxpoints.begin(), maxpoints.end());
    }
};