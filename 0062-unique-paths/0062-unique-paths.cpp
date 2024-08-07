class Solution {
public:
    
    int recurr(int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int top = recurr(i-1,j,dp);
        int left = recurr(i,j-1,dp);

        return dp[i][j] = top+left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n,-1));
        int i=m-1;
        int j=n-1;
        return recurr(i,j,dp);

    }
};