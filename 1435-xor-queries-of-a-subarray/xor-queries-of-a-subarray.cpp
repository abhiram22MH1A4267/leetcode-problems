class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto i : queries){
            int xor_ele = 0;
            for(int j = i[0]; j <= i[1]; j++){
                xor_ele ^= arr[j];
            }
            ans.push_back(xor_ele);
        }
        return ans;
    }
};