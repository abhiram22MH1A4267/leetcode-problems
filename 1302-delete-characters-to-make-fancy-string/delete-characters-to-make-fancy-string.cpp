class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        if(n < 3) return s;
        string ans;
        for(int i = 0; i < n-2; i++){
            if(s[i] == s[i+1] && s[i+1] == s[i+2]){
                continue;
            }
            else{
                ans += s[i];
            }
        }
        ans += s.substr(n-2,2);
        return ans;
    }
};