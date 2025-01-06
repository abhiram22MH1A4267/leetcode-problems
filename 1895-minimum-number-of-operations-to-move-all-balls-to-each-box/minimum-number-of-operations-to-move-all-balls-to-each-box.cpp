class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>ans(n,0), p;
        for(int i = 0; i < n; i++){
            if(boxes[i] == '1'){
                p.push_back(i);
                ans[0] += i;
            }
        }
        int m = p.size(), l = 0, r = m;
        for(int i = 1, j = 0; i < n; i++){
            if(j < m && i > p[j]){
                l++;
                r--;
                j++;
            }
            ans[i] = ans[i-1]+l-r;
        }
        return ans;
    }
};