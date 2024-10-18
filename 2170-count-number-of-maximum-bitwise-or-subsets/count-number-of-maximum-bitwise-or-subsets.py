class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        n = len(nums)
        max_bitwise = 0
        for i in nums:
            max_bitwise = max_bitwise | i

        ans = 0
        for i in range(1,2**n):
            a = format(i, 'b')
            a = a.zfill(n)
            sub_bitwise = 0
            for i in range(len(a)):
                if a[i] == '1':
                    sub_bitwise = sub_bitwise | nums[i]
            if(sub_bitwise == max_bitwise):
                ans += 1
        return ans