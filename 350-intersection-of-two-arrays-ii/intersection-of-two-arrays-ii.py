class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d = {}
        d1 = {}
        for i in nums1:
            if i not in d:
                d[i] = 1
            else:
                d[i] += 1
        for i in nums2:
            if i not in d1:
                d1[i] = 1
            else:
                d1[i] += 1
        ans = []
        for i in d.keys():
            if i in d1.keys():
                a = min(d[i],d1[i])
                for j in range(a):
                    ans.append(i)
        return ans 