class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int i = 0, j = arr.size();
        int n = arr.size();
        vector<int>ans;
        vector<int>v = arr;
        sort(v.begin(),v.end());
        if(v == arr) return ans;
        while(i < j){
            if(arr[i] == n){
                ans.push_back(i+1);
                ans.push_back(n);
                reverse(arr.begin(),arr.begin()+(i+1));
                reverse(arr.begin(),arr.begin()+j);
                i = -1;
                j--;
                n--;
            }
            i++;
        }
        return ans;
    }
};