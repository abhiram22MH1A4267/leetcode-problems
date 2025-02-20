class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums[0])
        for i in range(2**n):
            a = format(i, 'b')
            a = a.zfill(n)
            if(a not in nums):
                return a
        return ""