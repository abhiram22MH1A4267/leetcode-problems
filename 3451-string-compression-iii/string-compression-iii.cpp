class Solution {
public:
    string compressedString(string word) {
        pair<char,int>Pair = {word[0], 1};
        int n = word.length();
        string ans;
        for(int i = 1; i < n; i++){
            if(Pair.first == word[i]) Pair.second++;
            else{
                while(Pair.second > 9){
                    ans += to_string(9) + Pair.first;
                    Pair.second -= 9;
                }
                if(Pair.second != 0){
                    ans += to_string(Pair.second) + Pair.first;
                }
                Pair = {word[i], 1};
            }
        }
        if(Pair.second > 9){
            while(Pair.second > 9){
                ans += to_string(9) + Pair.first;
                Pair.second -= 9;
            }
            if(Pair.second != 0){
                ans += to_string(Pair.second) + Pair.first;
            }
        }
        else{
            ans += to_string(Pair.second) + Pair.first;
        }
        
        return ans;
    }
};