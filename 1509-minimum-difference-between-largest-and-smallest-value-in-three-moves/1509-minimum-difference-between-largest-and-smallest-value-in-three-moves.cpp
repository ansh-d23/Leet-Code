class Solution {
public:
    int minDifference(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mini = INT_MAX;
        if(n<=3) return 0;
        for(int i=1;i<=4;i++){
            mini = min(mini , abs(nums[n-i]-nums[4-i]));
        }

        return mini;

        
    }
};