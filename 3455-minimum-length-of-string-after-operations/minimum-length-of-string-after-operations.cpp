class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        for(char ch : s){
            mp[ch]++;
        }
        for(auto it : mp){
            while(it.second >= 3){
                it.second -= 2;
                n -= 2;
            }
        }
        return n;
    }
};