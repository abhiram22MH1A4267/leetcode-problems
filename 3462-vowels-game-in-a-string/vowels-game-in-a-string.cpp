class Solution {
public:
    int vowelCount(string &s){
        int n = s.length(), count = 0;
        string vowels = "aeiou";
        for(char ch : s){
            if(find(vowels.begin(), vowels.end(), ch) != vowels.end()) count++;
        }

        return count;
    }
    bool doesAliceWin(string s) {
        int n = vowelCount(s);
        if(n == 0) return false;
        // else if((n & 1) == 0) return true;
        return true;
    }
};