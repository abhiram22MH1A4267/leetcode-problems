class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        ans = []
        for i in arr2:
            a = arr1.count(i)
            for j in range(a):
                ans.append(i)
        arr1.sort()
        for i in arr1:
            if i not in ans:
                a = arr1.count(i)
                for j in range(a):
                    ans.append(i)
        return ans