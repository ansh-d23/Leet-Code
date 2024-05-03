class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0,mid;
        int end=nums.size()-1;
        if(nums.size()==1) return 0;
        if(nums[start]>nums[start+1]) return start;
        if(nums[end]>nums[end-1]) return end;
        
        while(start<end){
            mid = (start+end)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }else if(nums[mid]>nums[mid+1]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return mid ;
    }
};