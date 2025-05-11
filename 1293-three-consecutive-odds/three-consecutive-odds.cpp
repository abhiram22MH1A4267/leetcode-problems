class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size(), count = 0;
        for(int i : arr){
            if((i & 1) == 1) count++;
            else count = 0;
            if(count == 3){
                return true;
            }
        }
        return false;
    }
};