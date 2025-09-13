class Solution {
public:
    int maxFreqSum(string s) {
        string vowels = "aeiou";
        unordered_map<char, int> vowelFreq, consFreq;

        int val1 = 0, val2 = 0;
        for(char ch : s){
            if(find(vowels.begin(), vowels.end(), ch) != vowels.end()){
                vowelFreq[ch]++;
                val1 = max(val1, vowelFreq[ch]);
            }
            else{
                consFreq[ch]++;
                val2 = max(val2, consFreq[ch]);
            }
        }

        return val1 + val2;
    }
};