class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hash[100001]={0};
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<nums.size()+1;i++){
            if(hash[i]>=2){
                return i;
            }
        }
        return 0;
    }
};