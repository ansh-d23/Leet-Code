class Solution {
public:
    int recurr(vector<int>& nums, vector<int>& dp,int i){
        if(i==0) return nums[i];
        if(i<=0) return 0;

        if(dp[i]!=-1) return dp[i];

        int take = nums[i] + recurr(nums,dp,i-2);
        int nottake = recurr(nums,dp,i-1);

        return dp[i] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
        vector<int> temp1,temp2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp2.push_back(nums[i]);
            if(i!=n-1) temp1.push_back(nums[i]);
        }

        
        int t1 = temp1.size();

        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        return max(recurr(temp1,dp1,t1-1),recurr(temp2,dp2,t1-1));
        
    }
};