class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();

        int varSum=0;
        int maxm=INT_MIN;

        for(int i=0;i<n;i++){
            varSum+=nums[i];
            if(varSum > maxm){
                maxm=varSum;
            }
            if(varSum<0) varSum=0;
        }

        return maxm;    
    }
};