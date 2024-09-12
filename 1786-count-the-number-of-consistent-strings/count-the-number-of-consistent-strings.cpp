class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>freq(26,0);
        int ans = 0;
        for(char i : allowed){
            freq[i-'a'] = 1;
        }
        for(auto i : words){
            bool found = true;
            for(char j : i){
                if(freq[j - 'a'] != 1){
                    found = false;
                    break;
                }
            }
            if(found) ans++;
        }
        return ans;
    }
};