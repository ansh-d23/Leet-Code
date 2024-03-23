class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        int minn=INT_MAX;
        if(k==1) return 0;
        int i=0,j=i+k-1;
        while(j<nums.size()){
            minn=min(minn,nums[i]-nums[j]);
            i++;
            j++;
        }
        return minn;
    }
};