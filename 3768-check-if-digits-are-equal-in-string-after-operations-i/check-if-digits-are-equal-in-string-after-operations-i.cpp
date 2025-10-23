class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();

        while(n > 2){
            string s1 = "";
            for(int i = 1; i < n; i++){
                s1 += to_string((s[i] + s[i-1]) % 10);
            }
            s = s1;
            n--;
        }

        return s[0] == s[1];
    }
};