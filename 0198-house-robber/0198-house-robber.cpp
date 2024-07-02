class Solution {
public:
    
    int recurr(int i,vector<int>& nums,vector<int>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int pick = recurr(i+2,nums,dp) + nums[i];
        int notpick = 0 + recurr(i+1,nums,dp);

        return dp[i] = max(pick,notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);

        return recurr(0,nums,dp);
        
    }
};