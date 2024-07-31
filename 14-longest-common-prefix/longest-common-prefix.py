class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort(key = len)
        ans = ""
        for i in range(len(strs[0])):
            a = strs[0][:i+1]
            for j in strs:
                if a != j[:i+1]:
                    return ans
            ans = a
        return ans