class Solution {
public:

    void backtrack(int i,vector<int> ds,vector<int>& nums,int target, int &ans){
        if(target==0){
            ans++;
            return;
        }

        if(target>=0){
            ds.push_back(nums[i]);
            backtrack(i+1,ds,nums,target-nums[i],ans);
            ds.pop_back();
        }
        

        
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        vector<int> ds;
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        int target;
        if(sum%k==0) target = sum/k;
        else return false;

        int ans=0;

        backtrack(0,ds,nums,target,ans);

        if(ans==k) return true;
        else return false;
        
    }
};