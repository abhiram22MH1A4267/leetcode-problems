class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        n = len(matrix)
        m = len(matrix[0])
        ans = []
        for i in range(len(matrix)):
            min_ele = min(matrix[i])
            for j in range(len(matrix[i])):
                if matrix[i][j] == min_ele:
                    k = 0
                    while(k < n):
                        if(matrix[k][j] <= matrix[i][j]):
                            k += 1
                        else:
                            break
                    if(k == n):
                        ans.append(matrix[i][j])
        return ans