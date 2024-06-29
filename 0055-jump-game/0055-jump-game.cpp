class Solution {
public:
    bool canJump(vector<int>& nums) {

        int maxindex=nums[0];

        for(int i=1;i<=maxindex && i<nums.size();i++){
            if(i+nums[i]> maxindex){
                maxindex=i+nums[i];
            }
            if(i==maxindex){
                maxindex=i+nums[i];
            }
        }

        cout<<maxindex;

        if(maxindex>=nums.size()-1) return true;
        else return false;
        
    }
};