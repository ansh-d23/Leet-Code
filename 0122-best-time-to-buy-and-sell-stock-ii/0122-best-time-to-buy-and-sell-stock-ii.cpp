class Solution {
public:
    int memo(int i,int buy,vector<int>& prices,vector<vector<int>>& dp){

        if(i==prices.size()) return 0;


        int profit = 0;
        if(buy){
            profit  = max(-prices[i] + memo(i+1,0,prices,dp), memo(i+1,1,prices,dp));
        }else{
            profit = max(prices[i] + memo(i+1,1,prices,dp), memo(i+1,0,prices,dp));
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return memo(0,1,prices,dp);

    }
};