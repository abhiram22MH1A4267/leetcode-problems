class Solution {
public:
    int totalMoney(int n) {
        int lastWeek = 28, totalWeeks = n / 7, remainDays = n % 7;
        int res = 0, weeks = 0;
        while(weeks < totalWeeks){
            res += lastWeek;
            lastWeek += 7;
            weeks++;
        }

        for(int i = totalWeeks+1; i <= totalWeeks + remainDays; i++){
            res += i;
        }

        return res;
    }
};