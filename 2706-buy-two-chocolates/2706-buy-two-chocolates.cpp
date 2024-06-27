class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {

        if(prices.size()==1) return money;

        sort(prices.begin(),prices.end());

        int temp = prices[0]+prices[1];

        if(temp<=money){
            return money-temp;
        }else{
            return money;
        }

        
        
    }
};