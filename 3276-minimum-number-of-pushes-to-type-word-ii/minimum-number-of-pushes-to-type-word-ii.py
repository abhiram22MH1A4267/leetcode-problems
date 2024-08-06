class Solution:
    def minimumPushes(self, word: str) -> int:
        count = Counter(word)
        ans = 0
        for i, x in enumerate(sorted(count.values(), reverse = True)):
            ans += (i // 8+1) * x
        return ans