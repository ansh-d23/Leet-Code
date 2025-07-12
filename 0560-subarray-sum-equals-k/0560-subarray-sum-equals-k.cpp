class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // O(n^3) approach -> checking each and every sub array and finding sum
        // O(n) => will be solved using prefix sum and map

        int n = nums.size();
        unordered_map<int,int> mpp;

        mpp[0]++;
        int ans=0;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            int fnd = sum-k;
            if(mpp.find(fnd) != mpp.end()){
                ans+=mpp[fnd];
            }
            mpp[sum]++;
        }

        return ans;
    }
};