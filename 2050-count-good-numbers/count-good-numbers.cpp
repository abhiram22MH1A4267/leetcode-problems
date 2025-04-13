class Solution {
public:
    int mod = 1e9+7;
    long long power(long long base, long long exp){
        long long result = 1;
        while(exp > 0){
            if((exp & 1) == 1){
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2, odd = n/2;
        long long ans = (power(5, even) * power(4, odd)) % mod;
        return ans;
    }
};