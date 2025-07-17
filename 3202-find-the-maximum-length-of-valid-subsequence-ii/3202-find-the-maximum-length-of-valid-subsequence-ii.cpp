class Solution {
public:
      int maximumLength(vector<int>& nums, int k) {
        int max_len = 0;
        for (int target_sum = 0; target_sum < k; ++target_sum) {
            vector<int> dp(k, 0);
            
            for (int num : nums) {
                int rem = num % k;
                int prev_rem = (target_sum - rem + k) % k;
                
                dp[rem] = dp[prev_rem] + 1;
            }
            
            int current_max = 0;
            if (!dp.empty()) {
                current_max = *max_element(dp.begin(), dp.end());
            }
            
            max_len = max(max_len, current_max);
        }
        
        return max_len;
    }
};