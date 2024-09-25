class Solution {
public:
    int solve(vector<int>& nums,int k){
        int left = 0;
        int right = 0;
        int odd_count=0;
        int ans=0;

        while(right < nums.size()){

            if(nums[right]%2 != 0) odd_count++;

            while(odd_count > k){
                if(nums[left]%2 !=0){
                    odd_count--;
                }
                left++;
            }

            ans+= right-left+1;

            right++;
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {

        int x = solve(nums,k);
        int y = solve(nums,k-1);

        return x-y;
    }
};