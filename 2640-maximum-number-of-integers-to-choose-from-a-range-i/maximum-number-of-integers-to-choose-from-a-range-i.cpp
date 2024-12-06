class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int>mp;
        for(int i : banned){
            mp[i]++;
        }
        long long sum = 0;
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(mp.find(i) == mp.end()){
                sum += i;
                if(sum > maxSum) break;
                count++;
            } 
        }
        return count;
    }
};