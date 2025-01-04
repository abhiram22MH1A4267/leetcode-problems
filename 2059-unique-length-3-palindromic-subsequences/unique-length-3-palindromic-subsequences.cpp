class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>arr1(26,0);
        for(auto i : s){
            arr1[i - 'a']++;
        }
        vector<int>arr2(26,0);
        unordered_set<int>S;
        for(int i = 0; i < s.length(); i++){
            int t = s[i] - 'a';
            arr1[t]--;
            for(int j = 0; j < 26; j++){
                if(arr2[j] > 0 && arr1[j] > 0){
                    S.insert(26*t + j);
                }
            }
            arr2[t]++;
        }
        return S.size();
    }
};