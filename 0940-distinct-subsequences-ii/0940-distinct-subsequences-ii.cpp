class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[0]=1;
        int mod=1e9+7;
        unordered_map<char,int>last;

        for(int i=1;i<=n;i++){
            dp[i] = (2*dp[i-1])%mod;
            if(last.find(s[i-1])!=last.end()) dp[i] = (dp[i]-dp[last[s[i-1]]-1] + mod)%mod;
            last[s[i-1]]=i;
        }

        return (dp[n] - 1 + mod)%mod;
    }
};