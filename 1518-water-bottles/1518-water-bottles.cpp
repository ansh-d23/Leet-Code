class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int water_drink = numBottles;
        int rem=0;
        int empty = numBottles;

        while(empty >= numExchange){
            rem = empty%numExchange;
            empty/=numExchange;
            water_drink += empty ;
            empty += rem;
        }

        return water_drink;
        
    }
};