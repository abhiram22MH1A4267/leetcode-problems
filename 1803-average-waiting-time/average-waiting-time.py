class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        presum = sum(customers[0])
        c = 0
        for i in range(1,len(customers)):
            if presum > customers[i][0]:
                c += presum+customers[i][1]-customers[i][0]
                presum += customers[i][1]
            else :
                presum = sum(customers[i])
                c += customers[i][1]
        c += customers[0][1]
        return c/len(customers)