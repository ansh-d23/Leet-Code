class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();++j){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int left=j+1;
                int right=nums.size()-1;
                while(left<right){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[left];
                    sum+=nums[right];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++; right--;
                        while(left<right && nums[left]==nums[left-1]) left++;
                        while( left<right && nums[right]==nums[right+1]) right--;
                    }
                     else if(sum < target) left++;
                    else right--;
                }
            }
            
        }
        return ans;
    }
};