class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        int dip=0;
        int consicutive=0;

        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                dip++;
            }else{
                if( (nums[i]!=nums[i-1]) && (nums[i] != (nums[i-1]+1)) ){
                    return false;
                }
            }
        }

        return dip<=1 ? true : false;
    }
};