class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>arr1 = arr;
        sort(arr1.begin(), arr1.end());
        unordered_map<int,int>mp;
        int value = 1;
        for(int i = 0; i < arr1.size(); i++){
            if(mp.find(arr1[i]) == mp.end()){
                mp[arr1[i]] = value;
                value++;
            }
        }
        for(int i = 0; i < arr1.size(); i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};