class Solution {
public:
    string clearDigits(string s) {
        int count = 0, n = s.length();
        for(int i = 0; i < n; i++){
            if(isdigit(s[i]) && count > 0) count--;
            else s[count++] = s[i];
        }
        s.resize(count);
        return s;
    }
};