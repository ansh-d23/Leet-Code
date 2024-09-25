class Solution {
public:
    int solve(vector<int> nums,int goal){
        if(goal<0) return 0;
        int left = 0;
        int right = 0;
        int sum=0;
        int max_arr = 0;

        while(right < nums.size()){

            sum+=nums[right];

            while(sum > goal){
                sum-=nums[left++];
            }

            max_arr += (right-left+1);

            right++;
        }

        return max_arr;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int x = solve(nums,goal);
        int y = solve(nums,goal-1);

        return x-y;
        
    }
};