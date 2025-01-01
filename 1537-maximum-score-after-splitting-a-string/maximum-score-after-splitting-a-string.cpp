class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zero = 0;
        for(char i : s){
            if(i == '0') zero++;
            else ones++;
        }
        int ans = 0, s1 = 0, s2 = 0;
        for(int i = 0; i < s.length()-1; i++){
            if(s[i] == '0'){
                s1 += 1;
            }
            else{
                ones--;
            }
            ans = max(ans, s1+ones);
        }
        return ans;
    }
};