class Solution {
public:
    
    void subsets(int i,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans){

        if(i==nums.size()){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[i]);
        subsets(i+1,nums,ds,ans);
        ds.pop_back();
        
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        subsets(i+1,nums,ds,ans);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;
        
        sort(nums.begin(),nums.end());

        subsets(0,nums,ds,ans);
        
        return ans;
        
    }
};