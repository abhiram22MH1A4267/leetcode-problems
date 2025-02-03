class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        int n = arr.size(), count1 = 1, count2 = 1, ans = 0;
        for(int i = 0; i < n-1; i++){
            if(arr[i] < arr[i+1]){
                count1++;
            }
            else{
                ans = max(ans, count1);
                count1 = 1;
            }
            if(arr[i] > arr[i+1]){
                count2++;
            }
            else{
                ans = max(ans,count2);
                count2 = 1;
            }
            cout<<ans<<endl;
        }
        ans = max(ans,count1);
        ans = max(ans,count2);
        return ans;
    }
};