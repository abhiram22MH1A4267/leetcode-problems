class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        s1 = list(s1.split())
        s2 = list(s2.split())
        ans = []
        for i in s1:
            if s1.count(i) == 1:
                if i not in s2:
                    ans.append(i)
        for i in s2:
            if s2.count(i) == 1:
                if i not in s1:
                    if i not in ans:
                        ans.append(i)
        return ans