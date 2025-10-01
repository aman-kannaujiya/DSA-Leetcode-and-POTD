class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = numBottles;      // initially drink all full bottles
        int empty = numBottles;      // now you have all empty bottles

        while (empty >= numExchange) {
            int newBottles = empty / numExchange;   // exchange empties for full bottles
            drank += newBottles;                    // drink them
            empty = empty % numExchange + newBottles; // update empties
        }

        return drank;
    }
};
