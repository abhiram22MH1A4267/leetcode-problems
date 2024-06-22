class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        count = [0]*(n+1)
        count[0] = 1
        ans = 0
        t = 0
        for i in nums:
            t += i&1
            if t-k >= 0:
                ans += count[t-k]
            count[t] += 1
        return ans