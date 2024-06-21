class Solution {
public:
    void permutations(vector<int> &freq,vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds){

        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                permutations(freq,nums,ans,ds);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> ds;

        vector<int> freq(nums.size(),0);

        permutations(freq,nums,ans,ds);
        return ans;
    }
};