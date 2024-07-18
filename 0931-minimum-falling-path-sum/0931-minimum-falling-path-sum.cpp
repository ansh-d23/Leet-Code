class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp(n,vector<int>(n));

        for(int i=0;i<n;i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            int d_left = INT_MAX, d_mid = INT_MAX, d_right = INT_MAX;
            for(int j=n-1;j>=0;j--){
                if(j>0)  d_left = matrix[i][j] + dp[i+1][j-1];
                d_mid = matrix[i][j] + dp[i+1][j];
                if(j<n-1) d_right = matrix[i][j] + dp[i+1][j+1];
                dp[i][j] = min({d_left,d_mid,d_right});
            }
        }
        
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,dp[0][i]);
        }

        return mini;
    }
};