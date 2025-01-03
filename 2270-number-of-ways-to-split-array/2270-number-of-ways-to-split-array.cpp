class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int n = nums.size();
        vector<long long> prefix(n);
        long long sum=0;
        int ans=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix[i] = nums[i] + ((i-1)>=0 ? prefix[i-1] : 0);
        }

        for(int i=0;i<n-1;i++){
            if(prefix[i] >= (sum-prefix[i])) ans++;
        }

        return ans;

        
    }
};