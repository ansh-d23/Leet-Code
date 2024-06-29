class Solution {
public:
    bool backtrack(int k, vector<int> &nums, int target, int subsum, int start, vector<int>& used) {
        if (k == 0) return true;
        if (subsum == target)
            return backtrack(k - 1, nums, target, 0, 0, used);

        for (int j = start; j < nums.size(); j++) {
            if (!used[j] && subsum + nums[j] <= target) {
                used[j] = 1;
                if (backtrack(k, nums, target, subsum + nums[j], j + 1, used)) return true;
                used[j] = 0;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        vector<int> used(nums.size(), 0);

        return backtrack(k, nums, target, 0, 0, used);
    }
};
