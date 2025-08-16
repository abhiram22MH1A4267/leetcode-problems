class Solution {
public:
    int rev(int num){
        int ans = 0;
        while(num != 0){
            ans = (ans * 10) + num % 10;
            num /= 10;
        }
        return ans;
    }
    int maximum69Number (int num) {
        int rev_num = rev(num), ans = 0;
        bool done = 0;
        while(rev_num != 0){
            int d = rev_num % 10;
            if(d == 6 && !done){
                d = 9;
                done = 1;
            }
            ans = (ans * 10) + d;
            rev_num /= 10;
        }
        return ans;
    }
};