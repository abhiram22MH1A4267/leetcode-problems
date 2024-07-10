class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto it : logs){
            if(it == "../"){
                ans -= (ans>0);
            }
            else if(it != "./"){
                ans++;
            }
        }
        return ans;
    }
};