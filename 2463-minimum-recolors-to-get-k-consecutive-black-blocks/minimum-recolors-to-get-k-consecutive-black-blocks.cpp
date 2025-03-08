class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length(), w = 0, b = 0;
        for(int i = 0; i < k; i++){
            if(blocks[i] == 'W') w++;
            else b++;
        }
        int ans = w, i = 0;
        for(int j = k; j < n; j++){
            if(blocks[i] == 'W') w--;
            if(blocks[j] == 'W') w++;
            ans = min(ans, w);
            i++;
        }
        return ans;
    }
};