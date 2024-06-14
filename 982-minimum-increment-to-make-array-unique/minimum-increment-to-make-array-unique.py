class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        num = 0
        count = 0
        for i in nums:
            num = max(num,i)
            count += num-i
            num += 1
        return count
