class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n);
        stack<int> stk;

        int it = 2*n;
        for(int i=it-1;i>=0;i--){

            while(!stk.empty() && stk.top()<= nums[i%n]) stk.pop();
            if(i<n){
                ans[i] = stk.empty() ? -1 : stk.top();
            }
            stk.push(nums[i%n]);
        }

        return ans;
    }
};