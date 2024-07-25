class Solution {
public:
    int memo(int i,int j,string& a,string& b,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(a[i]==b[j]){
            return dp[i][j] = 1 + memo(i-1,j-1,a,b,dp);
        }

        int shift_i = memo(i-1,j,a,b,dp);
        int shift_j = memo(i,j-1,a,b,dp);
        return dp[i][j] = max(shift_i,shift_j);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return memo(n-1,m-1,text1,text2,dp);
    }
};