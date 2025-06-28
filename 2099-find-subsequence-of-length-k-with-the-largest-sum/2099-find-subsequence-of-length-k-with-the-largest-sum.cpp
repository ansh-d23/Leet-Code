class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MIN));
        vector<vector<bool>> take(n + 1, vector<bool>(k + 1, false));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {

                if (dp[i - 1][j] > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j];
                }
            
                if (j > 0 && dp[i - 1][j - 1] != INT_MIN) {
                    int newSum = dp[i - 1][j - 1] + nums[i - 1];
                    if (newSum > dp[i][j]) {
                        dp[i][j] = newSum;
                        take[i][j] = true;
                    }
                }
            }
        }

        vector<int> result;
        int i = n, j = k;
        while (j > 0 && i > 0) {
            if (take[i][j]) {
                result.push_back(nums[i - 1]);
                j--;
            }
            i--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
