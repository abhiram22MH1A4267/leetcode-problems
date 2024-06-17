class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = int(sqrt(c))
        i,j = a,0
        while(j <= i):
            s = (i**2)+(j**2)
            if s == c:
                return True
            elif s < c:
                j+=1
            elif s > c:
                i-=1
        return False