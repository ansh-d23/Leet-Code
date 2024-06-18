class Solution {
public:

    void subsets(int i,int n, vector<vector<int>>& ans,vector<int>& nums,vector<int>& temp,unordered_set<int> sett){

        if(i==n){
            ans.push_back(temp);
            return;
        }

        if(sett.find(nums[i]) == sett.end()){
            temp.push_back(nums[i]);
        }
        subsets(i+1,n,ans,nums,temp,sett);

        temp.pop_back();
        subsets(i+1,n,ans,nums,temp,sett);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        unordered_set<int> sett;
        subsets(0,n,ans,nums,temp,sett);   
        return ans;
        
    }
};