class Solution {
public:
    string res = "";
    bool generate(int n, int &k, int i, int prev){
        if(i == n) return --k == 0;
        for(char c = 'a'; c < 'd'; c++){
            if(c == prev) continue;
            if(generate(n, k, i+1, c)){
                res = c + res;
                return true;
            }
        }
        return false;
    }
    string getHappyString(int n, int k) {
        
        generate(n, k, 0, 'd');
        return res;
    }
};