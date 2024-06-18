class Solution {
public:

    int xor_total(vector<int>& nums){
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
    }
    
    int subsets(int i  , int n, vector<int>& ans,int sum,vector<int>& nums){

        if(i==n){
            return xor_total(ans);
        }

        ans.push_back(nums[i]);
        int l = subsets(i+1,n,ans,sum,nums);


        ans.pop_back();
        int r = subsets(i+1,n,ans,sum,nums);

        return l+r;
    }

    int subsetXORSum(vector<int>& nums) {

        int n=nums.size();
        vector<int> ans(n);
        int sum=0;
        return subsets(0,n,ans,sum,nums);
    }
};