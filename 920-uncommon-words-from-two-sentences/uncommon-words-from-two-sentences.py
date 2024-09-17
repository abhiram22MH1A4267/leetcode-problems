class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        s = s1 + " " + s2
        s = list(s.split())
        ans = []
        for i in s:
            if s.count(i) == 1:
                ans.append(i)
        return ans