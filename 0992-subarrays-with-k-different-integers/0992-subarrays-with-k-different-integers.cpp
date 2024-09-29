class Solution {
public:
    int ans(vector<int> nums,int k){

        int n = nums.size();
        unordered_map<int,int> mpp;
        int left=0;
        int right=0;
        int ans=0;

        while(right < n){

            mpp[nums[right]]++;

            while(mpp.size() > k){
                mpp[nums[left]]--;
                if(mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }

            ans += right-left+1;

            right++;
        }

        return ans;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int x = ans(nums,k);
        int y = ans(nums,k-1);

        return x-y;
    }
};