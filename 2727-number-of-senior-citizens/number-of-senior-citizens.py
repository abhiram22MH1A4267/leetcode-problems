class Solution:
    def countSeniors(self, details: List[str]) -> int:
        ans = 0
        for i in details:
            s = i[11:13]
            # print(s)
            if int(s) > 60:
                ans += 1
        return ans