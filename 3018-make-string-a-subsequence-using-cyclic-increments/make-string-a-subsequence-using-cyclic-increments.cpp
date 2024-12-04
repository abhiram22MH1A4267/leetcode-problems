class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, len = str2.length();
        for(char ch : str1){
            if(i < len && (str2[i] - ch + 26)%26 <= 1){
                i++;
            }
        }
        return i == len;
    }
};