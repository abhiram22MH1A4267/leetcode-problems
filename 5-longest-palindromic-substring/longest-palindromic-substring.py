class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) <= 1:
            return s
        maxi = 0
        max_str = s[0]
        for i in range(len(s)):
            for j in range(i+1,len(s)):
                if j-i+1 > maxi and s[i:j+1] == s[i:j+1][::-1]:
                    maxi = j-i+1
                    max_str = s[i:j+1]
        return max_str
        