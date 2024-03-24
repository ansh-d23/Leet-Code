class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*bool check = true;
        int i=1,j=1;
        while(j<nums.size()){
            if(nums[j-1]!=nums[j]){
                nums[i]=nums[j];
                i++; j++;
                check=true;
            }else if(nums[j-1]==nums[j] && check){
                nums[i]=nums[j];
                i++; j++;
                check=false;
            }else{
                j++;
            }
        }
        return i;*/
        int j=1;
        for(int i=1;i<nums.size();i++){
            if(j==1 || nums[i]!=nums[j-2]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};