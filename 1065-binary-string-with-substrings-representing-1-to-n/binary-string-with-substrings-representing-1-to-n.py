class Solution:
    def queryString(self, s: str, n: int) -> bool:
        
        arr = []
        for i in range(len(s)):
            s1 = s[i]
            arr.append(int(s1,2))
            for j in range(i+1,len(s)):
                s1 += s[j]
                arr.append(int(s1,2))
        for i in range(1,n+1):
            if(i not in arr):
                return False
        return True