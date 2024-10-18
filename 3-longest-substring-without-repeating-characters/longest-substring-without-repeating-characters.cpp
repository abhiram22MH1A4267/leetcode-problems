class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        string ans = "";
        int max_size = 0;
        while(j < s.length()){
            if(find(ans.begin(), ans.end(), s[j]) != ans.end()){
                int n = ans.length();
                max_size = max(max_size, n);
                while(ans[i] != s[j]){
                    i++;
                }
                ans = ans.substr(i+1);
                i = 0;
            }
            ans += s[j];
            j++;
        }
        cout<<ans;
        int n = ans.length();
        return max(max_size, n);
    }
};