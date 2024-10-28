const long long N = 100001;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        bitset<N>hasX = 0;
        int max_element = 0;
        for(int i : nums){
            hasX[i] = 1;
            max_element = max(max_element,i);
        }
        int maxStreak = 0;
        for(long long x = 2; x <= max_element; x++){
            if(hasX[x] == 0) continue;
            int streak = 1;
            for(long long y = x*x; y <= max_element; y *= y){
                if(hasX[y]){
                    streak++;
                    hasX[y] = 0;
                }
                else break;
            }
            maxStreak = max(maxStreak, streak);
            if(maxStreak == 5) break;
        }
        return maxStreak < 2 ? -1 : maxStreak;
    }
};