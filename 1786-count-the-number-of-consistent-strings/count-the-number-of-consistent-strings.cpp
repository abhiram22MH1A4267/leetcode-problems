class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0, count = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                if(find(allowed.begin(), allowed.end(), words[i][j]) != allowed.end()){
                    count++;
                }
            }
            if(words[i].length() == count){
                ans++;
            }
            count = 0;
        }
        return ans;
    }
};