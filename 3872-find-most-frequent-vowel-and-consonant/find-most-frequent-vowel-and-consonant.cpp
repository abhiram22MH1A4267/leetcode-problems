class Solution {
public:
    int maxFreqSum(string s) {
        string vowels = "aeiou";
        unordered_map<char, int> mp;

        int val1 = 0, val2 = 0;
        for(char ch : s){
            mp[ch]++;
            if(find(vowels.begin(), vowels.end(), ch) != vowels.end()){
                val1 = max(val1, mp[ch]);
            }
            else{
                val2 = max(val2, mp[ch]);
            }
        }

        return val1 + val2;
    }
};