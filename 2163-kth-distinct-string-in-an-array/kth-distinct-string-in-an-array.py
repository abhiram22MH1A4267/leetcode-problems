class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        d = collections.Counter(arr)
        count = 0
        for i in d.keys():
            if d[i] == 1:
                count += 1
            if count == k:
                return i
        return ""