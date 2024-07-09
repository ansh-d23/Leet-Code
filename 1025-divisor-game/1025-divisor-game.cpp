class Solution {
public:
    
    bool recurr(int n, vector<int>& dp){

        if(n<=1) return false;

        if(dp[n] != -1) return dp[n];

        for(int i=1;i<n;i++){
            if(n%i==0){
                if(recurr(n-i,dp) == 0){
                    dp[n]=1;
                    return true;
                }
            }
        }

        dp[n]=0;
        return false;
    }

    bool divisorGame(int n) {

        vector<int> dp(n+1,-1);
        return recurr(n,dp);
        
    }
};