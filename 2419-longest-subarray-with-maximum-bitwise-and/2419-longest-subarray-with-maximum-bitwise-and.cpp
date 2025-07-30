class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;

        int calc = nums[i];
        int maxm = 0;
        int max_len = 0;

        while (j < n) {
            calc &= nums[j];

            if(nums[j] > maxm || calc < maxm) {
                i = j;
                calc = nums[j];
            }

            if (calc >= maxm) {
                maxm = calc;
                max_len =  j - i + 1;
            }

            j++;
        }

        return max_len;
    }
};
