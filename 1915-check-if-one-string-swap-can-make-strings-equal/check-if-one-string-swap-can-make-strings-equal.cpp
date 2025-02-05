class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0, n = s1.length();
        unordered_map<char,int>mp1, mp2;
        for(int i = 0; i < n; i++){
            if(s1[i] != s2[i]){
                count++;
            }
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        for(auto it : mp1){
            if(mp2[it.first] != it.second) return false;
        }
        for(auto it : mp2){
            if(it.second != mp1[it.first]) return false;
        }
        if(count == 2 || count == 0) return true;
        return false;
    }
};