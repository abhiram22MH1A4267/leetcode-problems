class Solution {
public:
    int getLucky(string s, int k) {
        string s1 = "";
        for(int i = 0; i < s.size(); i++){
            s1 += to_string(s[i] - 'a' + 1);
        }
        while(k--){
            int n = 0;
            for(int i = 0; i < s1.size(); i++){
                n += s1[i] - '0';
            }
            s1 = to_string(n);
        }
        return stoi(s1);
    }
};