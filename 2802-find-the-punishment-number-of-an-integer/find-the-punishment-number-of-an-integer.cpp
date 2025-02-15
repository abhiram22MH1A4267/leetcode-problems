class Solution {
public:
    bool partition(int sq, int i){
        if(sq == i) return 1;
        if(sq == 0) return i == 0;
        int m = min(sq, 1000);
        for(int j = 10; j <= m; j*= 10){
            if(partition(sq/j, i-sq%j)) return 1;
        }
        return 0;
    }
    int punishmentNumber(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++){
            int sq = (i*i);
            count += (partition(sq,i)) ? sq : 0;
        }
        return count;
    }
};