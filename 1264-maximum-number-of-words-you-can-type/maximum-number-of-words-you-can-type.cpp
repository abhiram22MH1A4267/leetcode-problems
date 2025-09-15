class Solution {
public:
    vector<string> getWords(string text){
        vector<string>ans;
        string word = "";
        for(char ch : text){
            if(ch == ' '){
                ans.push_back(word);
                word = "";
            }
            word += ch;
        }
        ans.push_back(word);
        return ans;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string>arr = getWords(text);
        int res = arr.size();
        unordered_map<char, int> mp;
        for(char ch : brokenLetters) mp[ch]++;

        for(auto it : arr){
            for(char ch : it){
                if(mp.find(ch) != mp.end()){
                    res--;
                    break;
                }
            }
        }

        return res;
    }
};