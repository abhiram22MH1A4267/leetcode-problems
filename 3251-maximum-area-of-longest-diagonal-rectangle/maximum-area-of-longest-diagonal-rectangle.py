class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        a=[]
        p=1
        for i in dimensions:
            for j in i:
                p*=j
            a.append(p)
            p=1
        d=[]
        for i in dimensions:
            b=0
            for j in i:
                b+=j*j
            c=b
            d.append(c)
        v=max(d)
        dic=[]
        for i in range(len(d)):
            if d[i]==v:
                dic.append(a[i])
        return max(dic)
                
        