class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int mid;
        while(start<=end){
            mid = start + (end-start)/2;
            if(mid%2==0){
                if(mid!=0 && nums[mid]==nums[mid-1]){
                    end=mid-2;
                }else if(mid!=(nums.size()-1) && nums[mid]==nums[mid+1] ){
                    start=mid+2;
                }else{
                    return nums[mid];
                }
            }else{
                if(mid!=0 && nums[mid]==nums[mid-1]){
                    start=mid+1;
                }else if(mid!=(nums.size()-1) && nums[mid]==nums[mid+1]){
                    end=mid-1;
                }else{
                    return nums[mid];
                }
            }
        }
        return nums[mid];
    }
};