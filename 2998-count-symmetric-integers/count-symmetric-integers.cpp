class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i <= high; i++){
            string s = to_string(i);
            int n = s.length();

            if((n & 1) != 0) continue;

            int left = 0, right = 0, j = 0, k = n-1;

            while( j < k){
                left += s[j];
                right += s[k];
                j++;
                k--;
            }

            if(left == right) ans++;
        }
        return ans;
    }
};