class Solution:
    def maxArea(self, height: List[int]) -> int:
        i,j=0,len(height)-1
        m=0
        while(i<j):
            c=min(height[i],height[j])*(j-i)
            m=max(m,c)
            if(height[i]<height[j]):
                i+=1
            else:
                j-=1
        return m