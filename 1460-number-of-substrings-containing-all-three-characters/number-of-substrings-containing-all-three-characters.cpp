class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int>vec(3,-1);
        int count = 0;
        for(int i = 0; i < n; i++){
            vec[s[i] - 'a'] = i;
            if(vec[0] != -1 && vec[1] != -1 && vec[2] != -1){
                count += 1 + min({vec[0], vec[1], vec[2]});
            }
        }

        return count;
    }
};