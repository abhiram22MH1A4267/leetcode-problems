class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        if((m*n) != size){
            return {};
        }
        vector<vector<int>>ans;
        for(int i = 0; i < size; i += n){
            vector<int>arr;
            for(int j = i; j < i+n; j++){
                arr.push_back(original[j]);
            }
            ans.push_back(arr);
        }
        return ans;
    }
};