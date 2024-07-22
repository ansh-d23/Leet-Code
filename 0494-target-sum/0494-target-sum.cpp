class Solution {
public:
    int offset;
    int memo(int i,vector<int>& nums,int target,vector<vector<int>>& dp){
        if (i < 0) {
            if (target == 0) return 1;
            else return 0;
        }

        if (target + offset < 0 || target + offset >= dp[0].size()) return 0; 

        if (dp[i][target + offset] != -1) return dp[i][target + offset];

        int positive = memo(i - 1, nums, target - nums[i], dp);
        int negative = memo(i - 1, nums, target + nums[i], dp);

        return dp[i][target + offset] = positive + negative;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);

        if(abs(target) > sum) return 0;

        offset = sum;
        vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));

        return memo(n-1,nums,target,dp);
    }
};