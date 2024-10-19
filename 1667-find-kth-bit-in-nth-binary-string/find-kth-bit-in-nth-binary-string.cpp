class Solution {
public:
    char findKthBit(int n, int k) {
        string ans = "0";
        for(int i = 0; i < n; i++){
            string s = "";
            for(int i = 0; i < ans.size(); i++){
                if(ans[i] == '1') s += '0';
                else s += '1';
            }
            reverse(s.begin(), s.end());
            ans = ans + '1' + s;
        }
        return ans[k-1];
    }
};