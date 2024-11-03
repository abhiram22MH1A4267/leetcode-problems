class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        for i in range(len(s)):
            if s[i] == goal[0]:
                s1 = s[i:]+s[:i]
                if s1 == goal:
                    return True
        return False