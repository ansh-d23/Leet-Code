class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        // first pos is lower bound index
        // last pos is upper bound index - 1
        int n = nums.size();
        int fst = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int lst = upper_bound(nums.begin(),nums.end(),target) -nums.begin() - 1;

        if(fst==n || nums[fst] != target) return {-1,-1};

        return {fst,lst};
        
    }
};