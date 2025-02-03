class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int n = nums.size();
        int inc = 1;
        int dec = 1;

        for(int i=0;i<n;i++){
            int count=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[j-1]){
                    count++;
                }else{
                    break;
                }
            }
            inc = max(inc,count);
        }

        for(int i=0;i<n;i++){
            int count=1;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[j-1]){
                    count++;
                }else{
                    break;
                }
            }
            dec = max(dec,count);
        }

        return max(inc,dec);

        
    }
};