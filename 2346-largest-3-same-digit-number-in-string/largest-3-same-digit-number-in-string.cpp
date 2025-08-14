class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();

        string ans = "";

        for(int i = 1; i < n-1; i++){
            if((num[i-1] == num[i]) && (num[i] == num[i+1])){
                if(ans == ""){
                    ans = num.substr(i-1, 3);
                }
                else if((ans[0] - '0') < (num[i] - '0')) {
                    ans = num.substr(i-1, 3);
                }
            }
        }

        return ans;
    }
};