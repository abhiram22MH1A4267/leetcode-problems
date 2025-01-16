class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int x1 = 0, x2 = 0;
        if((n&1) != 0){
            for(int i : nums2){
                x2 ^= i;
            }
        }
        if((m&1) != 0){
            for(int i : nums1){
                x1 ^= i;
            }
        }
        return x1 ^ x2;
    }
};