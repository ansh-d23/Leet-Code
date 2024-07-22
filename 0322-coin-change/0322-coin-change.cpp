class Solution {
public:
    int memo(int i,vector<int>& coins,vector<vector<int>>& dp,int amount){
        if(amount==0) return 0;
        if(i==0){
            if(amount%coins[i]==0) return amount/coins[i];
            return INT_MAX;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        int nottake = 0 + memo(i-1,coins,dp,amount);
        int take  = INT_MAX;
        if (amount >= coins[i]) {
            int res = memo(i, coins, dp, amount - coins[i]);
            if (res != INT_MAX) {
                take = res + 1;
            }
        }

        return dp[i][amount] = min(nottake,take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res=memo(n-1,coins,dp,amount);
        return res==INT_MAX ? -1 : res  ;


    }
};