class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(),nums.end());
        long long count=0;
        int n=nums.size();
        vector<long long> powers(n);

        powers[0] = 1;
        for (int i = 1; i < n; ++i) {
            powers[i] = (powers[i - 1] * 2) % MOD;
        }

        int left=0;
        int right=n-1;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                count=(count+powers[right-left])%MOD;
                left++;
            }else right--;
        }
        return count;
    }
};