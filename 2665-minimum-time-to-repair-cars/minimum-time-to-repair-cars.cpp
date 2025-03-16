class Solution {
public:
    int freq[101] = {0}, mini = 101, maxi = 0;

    bool canRepair(int cars, long long mid){
        long long count = 0;
        for(int i = mini; i <= maxi; i++){
            count += freq[i] * (long long)sqrt(mid/i);
            if(count > cars) return 1;
        }
        return count >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        for(int i : ranks){
            mini = min(mini, i);
            maxi = max(maxi, i);
            freq[i]++;
        }

        long long l = 1, r = 1LL * mini * cars * cars;

        while(l < r){
            long long mid = (l+r) / 2;
            if(canRepair(cars, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};