class Solution {
public:
    int maximumLength(vector<int>& nums) {

       int n = nums.size();

       int odd_len = nums[0]%2;
       int even_len = nums[0]%2;
       int alter_len = 1;

       bool exp_even = nums[0]&1 ? true : false;

       for(int i=1;i<n;i++){
            if((exp_even==true && nums[i]%2==0) || (exp_even==false && nums[i]%2==1)){
                alter_len++;
                exp_even = !exp_even;
            }
            if(nums[i]%2==0) even_len++;
            else odd_len++;
       }

       return max({odd_len,even_len, alter_len});
    }
};