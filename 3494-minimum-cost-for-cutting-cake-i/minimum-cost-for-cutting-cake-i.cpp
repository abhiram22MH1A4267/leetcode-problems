class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int res = accumulate(horizontalCut.begin(), horizontalCut.end(), 0) + accumulate(verticalCut.begin(), verticalCut.end(), 0);
        for (int a : horizontalCut)
            for (int b : verticalCut)
                res += min(a, b);
        return res;
    }
};