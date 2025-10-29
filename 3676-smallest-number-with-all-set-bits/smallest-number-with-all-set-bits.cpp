class Solution {
public:
    int smallestNumber(int n) {
        int res = 0, i = 0;
        while(n > 0){
            res += pow(2, i);
            i++;
            n >>= 1;
        }

        return res;
    }
};