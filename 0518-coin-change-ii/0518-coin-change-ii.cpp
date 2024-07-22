class Solution {
public:
    int change(int target, vector<int>& coins) {

        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));

        for(int T=0;T<=target;T++){
            if(T%coins[0]==0) dp[0][T] = 1;
        }


        for(int i=1;i<n;i++){
            for(int t=0;t<=target;t++){
                int nottake  = dp[i-1][t];
                int take = 0;
                if(t >= coins[i]){
                    take  = dp[i][t-coins[i]];
                }
                dp[i][t] = nottake + take;
            }
        }

        return dp[n-1][target];
        
    }
};