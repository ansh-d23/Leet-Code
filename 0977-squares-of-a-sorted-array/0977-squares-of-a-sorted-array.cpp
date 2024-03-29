class Solution {
public:
    vector<int> ans(int i , int j,vector<int> nums){
        vector<int> ans(nums.size());
        int k=0;
        while(i<nums.size() && j>=0){
            if(nums[i]<abs(nums[j])){
                ans[k++]= pow(nums[i],2);
                i++;
            }else{
                ans[k++]= pow(nums[j],2);
                j--;
            }
        }
        for(int t=i;i<nums.size();i++){
            ans[k++]=pow(nums[t],2);
        }
        for(int t=j;j>=0;j--){
            ans[k++]=pow(nums[t],2);
        }
        return ans;
    }
    vector<int> sortedSquares(vector<int>& nums) {
            int r;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>=0){
                    r=i;
                    break;
                }
            }
            return ans(r,r-1,nums);
    }
};