class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(),sum=0;
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int r=sum%k;
            cout<<r<<" ";
            if(mpp.find(r)!=mpp.end()) {
                if(i-mpp[r]>=2) return true;
            }else{
                 mpp[r]=i;
            }
        }
        return false;
    }
};