class Solution {
public:
    int tab(string s,string t,vector<vector<unsigned long long>>& dp){
        int n = s.length();
        int m = t.length();

        for(int i =0;i<=n;i++) dp[i][0] = 1 ;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }
    int memo(int i,int j,string s, string t,vector<vector<int>>& dp){
        
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i]==t[j]){
            int cond1 = memo(i-1,j-1,s,t,dp);
            int cond2 = memo(i-1,j,s,t,dp);
            return dp[i][j] = cond1+cond2;
        }else{
            return dp[i][j] = memo(i-1,j,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));

        return tab(s,t,dp);
    }
};