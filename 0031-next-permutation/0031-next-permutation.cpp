class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int idx=-1;

        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        if(idx != -1){
            for(int j=n-1;j>idx;j--){
                if(nums[j]>nums[idx]){
                    swap(nums[j], nums[idx]);
                    break;
                }
            }
        }

        sort(nums.begin()+idx+1,nums.end());
        
    }
};