class Solution {
public:
    int countHillValley(vector<int>& nums) {

        int n = nums.size();
        vector<int> pref(n);
        vector<int> suff(n);

        pref[0]=-1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                pref[i] = pref[i-1];
            }else{
                pref[i] = nums[i-1];
            }
        }

        suff[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==nums[i+1]){
                suff[i] = suff[i+1];
            }else{
                suff[i] = nums[i+1];
            }
        }


        int ans=0;
        for(int i=1;i<n-1;i++){
            if(pref[i]>0 && suff[i]>0 && nums[i]>pref[i] && nums[i]>suff[i]){
                ans++;
                while(nums[i]==nums[i+1]) i++;
            }else
            if(pref[i]>0 && suff[i]>0 && nums[i]<pref[i] && nums[i]<suff[i]){
                ans++;
                while(nums[i]==nums[i+1]) i++;
            }
        }

        return ans;
    }
};