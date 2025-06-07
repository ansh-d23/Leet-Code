class Solution {
    void memo(int i, vector<int>& nums, stack<int>& stk, int& ans){

        if(i==nums.size()){
            if(!stk.empty()){
                if(stk.size() > ans) ans=stk.size();
            }
            return;
        }

        if(stk.empty() || nums[i]>stk.top()){
            //select
            stk.push(nums[i]);
            memo(i+1,nums,stk,ans);
            stk.pop();
        }
            //not select
            memo(i+1, nums, stk, ans);
    }

public:
    int lengthOfLIS(vector<int>& nums) {

        stack<int> stk;
        int ans = 0;

        memo(0,nums,stk,ans);

        return ans;
    }
};