class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        for(char ch : s){
            ans += (ch == '[') - (ch == ']');
            if(ans < 0) ans = 0;
        }
        return (ans+1) / 2;
    }
};