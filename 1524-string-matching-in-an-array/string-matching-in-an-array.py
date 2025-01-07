class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        s = set([])
        for i in range(len(words)):
            for j in range(len(words)):
                if i!= j and (words[j] in words[i]):
                    s.add(words[j])
        return list(s)