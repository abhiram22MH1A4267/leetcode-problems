class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool>sieve(right+1, true);
        sieve[0] = sieve[1] = false;
        for(int i = 2; i*i <= right; ++i){
            if(sieve[i]){
                for(int j = i*i; j <= right; j += i){
                    sieve[j] = false;
                }
            }
        }
        vector<int>primes;
        for(int i = left; i <= right; i++){
            if(sieve[i]){
                primes.push_back(i);
            }
        }
        int n = primes.size();
        if(n < 2){
            return {-1, -1};
        }
        int mini = INT_MAX;
        vector<int>ans(2, -1);
        for(int i = 1; i < n; i++){
            if((primes[i]-primes[i-1]) < mini){
                mini = primes[i] - primes[i-1];
                ans[0] = primes[i-1];
                ans[1] = primes[i];
            }
        }
        return ans;
    }
};