class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return true;

        for(int i=0;i<n-1;i++){
            int num1 = nums[i]%2==0 ? 1 : 0;
            int num2 = nums[i+1]%2==0 ? 1 : 0;

            if(num1==num2){
                return false;
            }          
        }

        return true;

        
    }
};