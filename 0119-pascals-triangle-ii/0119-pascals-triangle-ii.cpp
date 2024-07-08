class Solution {
public:
    int recurr(int i,int n,vector<vector<int>>& dp){
        if(i==0 || i==n) return 1;
        if(i>n) return 0;
        if(dp[i][n] != -1) return dp[i][n];

        int left = recurr(i-1,n-1,dp);
        int right = recurr(i,n-1,dp);

        return dp[i][n] = left+right;
    }
    vector<int> getRow(int rowIndex) {

        vector<int> ans(rowIndex+1);
        vector<vector<int>> dp(rowIndex+1, vector<int>(rowIndex+2,-1));

        for(int i=0;i<rowIndex+1;i++){
            ans[i] = recurr(i,rowIndex,dp);
        }
        return ans;
    }
};