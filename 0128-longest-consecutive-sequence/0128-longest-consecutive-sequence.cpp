class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        //sorting
        sort(nums.begin(),nums.end());

        int maxm=1,count=1;
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1]){
            if(nums[i]==nums[i+1]-1 ){
                count++;
            }else{
                maxm=max(maxm,count);
                count=1;
            }
            }
        }
        maxm=max(maxm,count);
        return maxm;
    }
};