class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto &num : nums){
            int temp = num * num;
            num = temp;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};