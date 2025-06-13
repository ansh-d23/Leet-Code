class Solution {

    bool memo(int l, int r, string& s, vector<vector<int>>& dp){

        if(l>=r) return true;

        if(dp[l][r] != -1) return dp[l][r];

        if(s[l]==s[r]){
            return dp[l][r] = memo(l+1,r-1,s,dp);
        }

        return dp[l][r] = false;
    }

public:
    string longestPalindrome(string s) {

        int n = s.length();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        int maxlen=0;
        int idx=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(memo(i,j,s,dp)){
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        idx = i;
                    }
                }
            }
        }

        return s.substr(idx, maxlen);
    }
};