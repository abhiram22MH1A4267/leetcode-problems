class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>mp;
        for(char i : s){
            mp[i]++;
        }
        int count = 0;
        for(auto it : mp){
            if(it.second % 2 == 1) count++;
        }
        return (count <= k && k <= s.size());
    }
};