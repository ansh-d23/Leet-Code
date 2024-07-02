class Solution {
public:
    
    int recurr(int i,vector<int>& cost,int n,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
    
        int left = recurr(i + 1, cost, n,dp) + (i > n ? 0 : cost[i]);
        int right = recurr(i + 2, cost, n,dp) + (i > n ? 0 : cost[i]);

        return dp[i] = min(left,right);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(recurr(0,cost,n,dp) , recurr(1,cost,n,dp)); 
    }
};