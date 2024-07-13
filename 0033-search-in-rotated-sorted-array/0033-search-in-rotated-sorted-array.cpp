class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int low = 0;
        int high = n;

        while(low<=high){
            int mid =  (high+low)/2;
            if(target == nums[mid]) return mid;
            if(nums[mid] >= nums[0]){
                if(target>=nums[low] && target<=nums[mid]){
                high=mid-1;
                }else{
                low = mid+1;
                }

            }else{
                if(target>=nums[mid] && target<=nums[high]){
                low=mid+1;
                }else{
                high = mid-1;
                }
            }
        }
        return -1;
    }
};