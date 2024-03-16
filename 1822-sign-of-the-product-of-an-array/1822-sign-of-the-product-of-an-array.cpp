class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negative=0;
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) return 0;
            else if(nums[i]<0) negative++;
        }
        if(negative%2 == 0) return 1;
        return -1;
    }
};