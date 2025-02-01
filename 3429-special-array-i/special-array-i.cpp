class Solution {
public:
    int setBits(int n){
        int count = 0;
        while(n){
            count += (n&1);
            n >>= 1;
        }
        return count;
    }
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            // int n1 = setBits(nums[i]), n2 = setBits(nums[i+1]);
            // if(((n1&1) == 0 && (n2&1) == 0) || ((n1&1) == 1) && (n2&1) ==  1) return false;
            if((nums[i]&1) == (nums[i+1]&1))  return false;
        }
        return true;
    }
};