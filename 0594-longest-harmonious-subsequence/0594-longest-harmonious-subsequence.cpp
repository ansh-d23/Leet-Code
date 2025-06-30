class Solution {
public:
    int findLHS(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int> mpp;

        for(auto& it : nums) mpp[it]++;

        int maxlen=0;

        for(int i=0;i<n;i++){
            mpp[nums[i]]--;

            if(mpp[nums[i]+1] > 0){
                int np1 = mpp[nums[i]+1];
                int n = mpp[nums[i]];
                maxlen = max(maxlen,n+np1+1);
            }

            if(mpp[nums[i]-1] > 0){
                int nm1 = mpp[nums[i]-1];
                int n  = mpp[nums[i]];
                maxlen = max(maxlen,n+nm1+1);
            }
        }

        return maxlen;
        
    }
};