class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int n = nums.size();
        vector<int> rprefix(n,-1);

        for(int i=n-2;i>=0;i--){
            rprefix[i]=max(rprefix[i+1],nums[i+1]);
        }

        int ans = -1;
        for(int i=0;i<n-1;i++){

            int left_max = rprefix[i];
            int val = nums[i];

            if(left_max > val){
               ans= max(ans, left_max-val);
            }
        }

        return ans; 
    }
};