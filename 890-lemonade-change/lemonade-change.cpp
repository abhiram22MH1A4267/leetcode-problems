class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0, count10 = 0;
        for(int i : bills){
            switch(i){
                case 5:
                    count5++;
                    break;
                case 10:
                    if(count5 > 0) count5--, count10++;
                    else return 0;
                    break;
                case 20:
                    if(count10 > 0 && count5 > 0) count5--, count10--;
                    else if(count5 > 2) count5-=3;
                    else return 0;
                    break;
            }
        }
        return -1;
    }
};