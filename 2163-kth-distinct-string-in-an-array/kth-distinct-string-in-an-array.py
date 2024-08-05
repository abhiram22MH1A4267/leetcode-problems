class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        d = {}
        for i in arr:
            if i not in d:
                d[i] = 1
            else:
                d[i] += 1
        count = 0
        for i in d.keys():
            if d[i] == 1:
                count += 1
            if count == k:
                return i
        return ""