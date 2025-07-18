class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix,suffix=prefix=1;
        int maxProduct=INT_MIN;
        for(int i=0;i<nums.size();i++){
             if(prefix==0) prefix=1;
             if(suffix==0) suffix=1;
             prefix*=nums[i];
             suffix*=nums[nums.size()-i-1];
             maxProduct = max(maxProduct,max(prefix,suffix));
        }
        return maxProduct;
    }
};