class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, res = 0;
        for(auto row : bank){
            int curr = count(row.begin(), row.end(), '1');
            if(curr > 0){
                res += prev * curr;
                prev = curr;
            }
        }

        return res;
    }
};