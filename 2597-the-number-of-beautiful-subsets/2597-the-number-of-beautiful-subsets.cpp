class Solution {
public:
    void backtrack(int index,int k, vector<int>& nums, int& count,unordered_map<int,int>& mpp) {

        if (index == nums.size()) {
            count++;
            return;
        }

        backtrack(index+1,k,nums,count,mpp);

        if(!mpp[nums[index]+k] && !mpp[nums[index]-k]){

            mpp[nums[index]]++;
            backtrack(index+1,k,nums,count,mpp);
            mpp[nums[index]]--;

        }
     
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        
        unordered_map<int,int> mpp;
        int count = 0;
        
        backtrack(0,k,nums, count,mpp);
        
        return count-1;
    }
};