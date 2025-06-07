class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        int n = nums.size();
        int i=0,j=0;
        int ans = 1;

        while(i<n && j<n){

            if(j+1<n && nums[j+1]>nums[j]){
                j++;
                ans = max(ans,j-i+1);
            }else{
                i=j+1;
                j=i;
            }      

        }

        return ans;
        
    }
};