class Solution {
public:
    int numWaterBottles(int numB, int numE) {
        int empty = numB%numE, Exchange = numB/numE;
        int ans = numB+Exchange;
        while((empty+Exchange) >= numE){
            int Exchange1 = (empty+Exchange)/numE;
            int empty1 = (empty+Exchange)%numE;
            Exchange = Exchange1;
            empty = empty1;
            ans += Exchange;
        }
        return ans;
    }
};