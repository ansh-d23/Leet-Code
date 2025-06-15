class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {

        long long ans = LLONG_MIN;

        if(m==1){
            for(auto& it : nums) ans = max(ans, (1LL*it)*it);
            return ans;
        }

        int n = nums.size();
        set<int> sett;

        for(int i=m-1;i<n;i++){
            sett.insert(nums[i - (m-1)]);
            long long mini = *(sett.begin());
            long long maxm = *(sett.rbegin());
            ans = max({ans, (1LL*nums[i])*maxm, (1LL*nums[i]*mini)});
        }

        return ans;
        
    }
};