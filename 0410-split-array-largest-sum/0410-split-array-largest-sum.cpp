class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();

        vector<vector<int>> dp(k+1,vector<int>(n+1,INT_MAX));
        vector<int> pref(n+1,0);

        pref[1]=nums[0];
        for(int i=2;i<=n;i++){
            pref[i] = pref[i-1] + nums[i-1]; 
        }

        //base case
        for(int i=1;i<=n;i++){
            dp[1][i] = pref[i];
        }

        for(int i=2;i<=k;i++){
            for(int j=i;j<=n;j++){
                for(int p=1;p<j;p++){
                    int last_subarray = pref[j] - pref[p];
                    int subarray_k = max(dp[i-1][p], last_subarray);
                    dp[i][j] = min(dp[i][j],subarray_k);
                }
            }
        }

        return dp[k][n];
    }
};