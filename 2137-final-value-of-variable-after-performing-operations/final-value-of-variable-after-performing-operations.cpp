class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(string s : operations){
            if(s[0] == '-' || s[s.length()-1] == '-') res--; 
            else res++;
        }
        return res;
    }
};