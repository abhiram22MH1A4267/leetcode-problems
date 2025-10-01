class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        while(numBottles >= numExchange){
            int exchangeValue = numBottles / numExchange;
            int remain = numBottles % numExchange;
            res += exchangeValue;
            numBottles = exchangeValue + remain;
        }

        return res;
    }
};