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

        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                long long sum=nums[i]+nums[j];
                if((j==i)  && sum<=target) count++;
                else if(sum<=target) count=(count+powers[j-i-1]) % MOD;
                else break;
            }
        }
        return count;
    }
};