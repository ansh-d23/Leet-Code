class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {

       int n = nums.size();
       int maxm = INT_MIN;

       for(int i=0;i<n;i++){
           int diff = abs(nums[i%n] - nums[(i+1)%n]);
           maxm = max(maxm, diff); 
       }

       return maxm;
    }
};