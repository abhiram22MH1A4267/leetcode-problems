class Solution {
public:
    string getVowel(string s, int n){
        string res = "";
        string vowels = "AEIOUaeiou";

        for(char ch : s){
            if(find(vowels.begin(), vowels.end(), ch) != vowels.end()) res += ch;
        }

        sort(res.begin(), res.end());
        return res;
    }
    string sortVowels(string s) {
        int n = s.length(), j = 0;
        string vowelChar = getVowel(s, n);

        string vowels = "AEIOUaeiou";

        for(int i = 0; i < n; i++){
            if(find(vowels.begin(), vowels.end(), s[i]) != vowels.end()){
                s[i] = vowelChar[j];
                j++;
            }
        }

        return s;
    }
};