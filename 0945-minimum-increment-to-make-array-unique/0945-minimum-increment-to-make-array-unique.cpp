class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int ans=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                int temp = (nums[i-1]-nums[i]+1);
                nums[i]+= temp;
                ans+=temp;
            }
        }

        return ans;
        
    }
};