class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j = 0, n = s.length();
        string ans;
        for(int i = 0; i < n; i++){
            if(j < spaces.size() && i == spaces[j]){
                ans += ' ';
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};