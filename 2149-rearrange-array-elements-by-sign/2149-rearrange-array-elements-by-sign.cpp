class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n);

        int pst=0;
        int neg=1;

        for(int i=0;i<n;i++){
            if(nums[i]>0 && pst<n){
                ans[pst]=nums[i];
                pst+=2;
            }else
            if(nums[i]<0 && neg<n){
                ans[neg]=nums[i];
                neg+=2;
            } 
        }

        return ans;    
    }
};