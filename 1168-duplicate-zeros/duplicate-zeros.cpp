class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int>ans;
        int i = 0;
        while(ans.size() < arr.size()){
            if(arr[i] != 0){
                ans.push_back(arr[i]);
            }
            else{
                if(arr.size()-ans.size() == 1){
                    ans.push_back(arr[i]);
                }
                else{
                    ans.push_back(arr[i]);
                    ans.push_back(arr[i]);
                }
            }
            i++;
        }
        arr = ans;
    }
};