class Solution:
    def fun(self,p,m,mid):
        count = 1
        prev = p[0]
        for i in range(1,len(p)):
            if p[i]-prev >= mid:
                count += 1
                prev = p[i]
        return count >= m
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        mini = 1
        maxi = position[-1]-position[0]
        while maxi-mini > 1:
            mid = (maxi+mini)//2
            if self.fun(position,m,mid):
                mini = mid
            else:
                maxi = mid-1
        if self.fun(position,m,maxi):
            return maxi
        return mini