class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        n = len(nums)
        flipped,ans = 0,0
        isflipped = [0]*n
        for i in range(n):
            if i >= k:
                flipped ^= isflipped[i-k]
            if flipped == nums[i]:
                if i+k > n:
                    return -1
                isflipped[i] = 1
                flipped ^= 1
                ans += 1
        return ans