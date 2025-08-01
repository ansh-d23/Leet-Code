class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-2];

        int low=0;
        int high=n-2;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];

            if((mid%2==0 && nums[mid]==nums[mid-1]) || (mid%2==1 && nums[mid]==nums[mid+1])){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }


        return nums[n-1];
        
    }
};