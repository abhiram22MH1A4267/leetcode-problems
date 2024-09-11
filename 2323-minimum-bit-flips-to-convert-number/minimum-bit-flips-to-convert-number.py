class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        a = format(start,'b')
        b = format(goal,'b')
        n = max(len(a),len(b))
        a = a.zfill(n)
        b = b.zfill(n)
        ans = 0
        for i in range(n):
            if a[i] != b[i]:
                ans += 1
        return ans