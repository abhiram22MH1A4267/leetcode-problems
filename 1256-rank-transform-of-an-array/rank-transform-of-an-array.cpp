class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>arr1 = arr;
        sort(arr1.begin(), arr1.end());
        map<int,int>mp;
        int value = 1;
        for(int i = 0; i < arr1.size(); i++){
            if(mp.find(arr1[i]) == mp.end()){
                mp[arr1[i]] = value;
                value++;
            }
        }
        vector<int>ans;
        for(int i : arr){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};