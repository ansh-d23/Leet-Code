class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int currmax=0;
        int currmin=0;
        int globalmax=nums[0];
        int globalmin=nums[0];
        int total=0;

        for(int i=0;i<nums.size();i++){
            currmax = max(nums[i],currmax+nums[i]);
            currmin = min(nums[i],currmin+nums[i]);
            total+=nums[i];
            globalmax = max(globalmax,currmax);
            globalmin = min(globalmin,currmin);
        }

        return globalmax > 0 ? max(globalmax, total - globalmin) : globalmax;
        
    }
};