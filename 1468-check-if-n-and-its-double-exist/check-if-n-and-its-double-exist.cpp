class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp1, mp2;
        for(int i : arr){
            if(mp1.find(i*2) != mp1.end() || mp2.find(i) != mp2.end()) return 1;
            mp1[i]++;
            mp2[i*2]++;
        }
        return 0;
    }
};