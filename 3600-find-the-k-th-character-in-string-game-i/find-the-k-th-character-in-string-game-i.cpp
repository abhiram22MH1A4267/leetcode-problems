class Solution {
public:
    char kthCharacter(int k) {
        string ans = "a";
        while(ans.size() < k){
            string s = "";
            for(char ch : ans){
                s += char((((ch - 'a') % 26) + 97) + 1);
            }
            ans += s;
            cout<<ans<<endl;
        }
        return ans[k-1];
    }
};