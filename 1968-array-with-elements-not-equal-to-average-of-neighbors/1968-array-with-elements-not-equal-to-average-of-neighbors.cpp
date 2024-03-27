class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans(nums.size());
        int n = nums.size() / 2;
        int i=0;
        int j=n+1;
        for(int t=0;t<nums.size();t++){
            if(t%2==0){
                ans[t]=nums[i];
                i++;
            }else{
                ans[t]=nums[j];
                j++;
            }
        }
        return ans;
    }
}; 