#include <bits/stdc++.h>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count=0,mul=1,index;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                mul*=nums[i];
            }else{
                count++;
                index=i;
            }
        }

        if(count==0){
            for(int i=0;i<nums.size();i++){
                nums[i]=(mul/nums[i]);
            }
        }else if(count==1){
            fill(nums.begin(),nums.end(),0);
            nums[index]=mul;
        }else{
            fill(nums.begin(),nums.end(),0);
        }
        return nums;
    }
};