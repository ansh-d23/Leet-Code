class Solution {
public:
    int recurr(int i,int j,vector<vector<int>>& obs,vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(obs[i][j]==1) return 0;
        if(dp[i][j] != -1) return dp[i][j];


        int top = recurr(i-1,j,obs,dp);
        int left = recurr(i,j-1,obs,dp);

        return dp[i][j] = left+top;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        return recurr(n-1,m-1,obstacleGrid,dp); 
        
    }
};