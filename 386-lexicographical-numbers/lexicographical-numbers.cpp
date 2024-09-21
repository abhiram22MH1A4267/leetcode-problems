class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>arr;
        for(int i = 1; i <= n; i++){
            arr.push_back(to_string(i));
        }
        sort(arr.begin(), arr.end());
        vector<int>ans;
        for(int i = 0; i < n; i++){
            ans.push_back(stoi(arr[i]));
        }
        return ans;
    }
};