class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        ans = []
        res = []
        res1 = []
        for i in matrix:
            res.append(min(i))
        for j in range(len(matrix[0])):
            l = []
            for i in range(len(matrix)):
                l.append(matrix[i][j])
            res1.append(max(l))
        for i in res:
            if i in res1:
                ans.append(i)
        return ans