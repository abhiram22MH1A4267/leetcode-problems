class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        mini = -1
        maxi = -1
        end = -1
        counter = 0
        for i in range(len(nums)):
            if minK <= nums[i] <= maxK:
                mini = i if nums[i] == minK else mini
                maxi = i if nums[i] == maxK else maxi
                counter += max(0,min(mini,maxi)-end)
            else:
                mini = -1
                maxi = -1
                end = i
        return counter