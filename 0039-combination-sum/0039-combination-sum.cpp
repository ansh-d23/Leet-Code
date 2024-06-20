class Solution {
public:
    
    void combination(int i,int target,vector<int>& candidates, vector<int>& arr, vector<vector<int>>& ans){

        if(i==candidates.size()){
            if(target==0) ans.push_back(arr);
            return;
        }

        if(candidates[i]<=target){
            arr.push_back(candidates[i]);
            combination(i,target-candidates[i],candidates,arr,ans);
            arr.pop_back();
        }
        combination(i+1,target,candidates,arr,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> arr;
        vector<vector<int>> ans;

        combination(0,target,candidates,arr,ans);
        return ans;    
    }
};