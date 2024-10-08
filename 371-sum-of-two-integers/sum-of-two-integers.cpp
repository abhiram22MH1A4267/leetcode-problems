class Solution {
public:
    int getSum(int a, int b) {
        int ans = (a ^ b) + (2 * (a & b));
        return ans;
    }
};