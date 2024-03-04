class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumr=0;
        for(int i=0;i<nums.size();i++){
            sumr+=nums[i];
        }
        int suml=0;
        for(int i=0;i<nums.size();i++){
            sumr-=nums[i];
            if(sumr==suml){
                return i;
            }
            suml+=nums[i];
        }
        return -1;
    }
};