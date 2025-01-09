class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        n = len(pref)
        ans = 0
        for i in words:
            if pref == i[:n]:
                ans += 1
        return ans