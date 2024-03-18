class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) count++;
            else{
                ans+=1LL*(1LL*(count + 1)* 1LL*count)/2;
                count=0;
              }
            }
            ans+= 1LL*(1LL*count * 1LL*(count+1))/2;
            return ans;
    }
};