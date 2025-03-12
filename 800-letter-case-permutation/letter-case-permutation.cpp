class Solution {
public:
    vector<string>ans;
    void Backtrack(string &s, int index, int n){
        if(index >= n) return;
        if(int(s[index]) >= 65 && int(s[index]) <= 91){
            s[index] += 32;
            ans.push_back(s);
            Backtrack(s, index+1, n);
            s[index] -= 32;
        }
        else if(int(s[index] > 96)){
            s[index] -= 32;
            ans.push_back(s);
            Backtrack(s, index+1, n);
            s[index] += 32;
        }
        Backtrack(s, index+1, n);

    }
    vector<string> letterCasePermutation(string s) {
        int n = s.length();
        ans.push_back(s);
        Backtrack(s, 0, n);
        sort(ans.begin(), ans.end(), [] (const string &s1, string &s2) {
            return s1 > s2;
        });
        return ans;
    }
};