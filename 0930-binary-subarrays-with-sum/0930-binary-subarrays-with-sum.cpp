class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int n = nums.size();
        // int count=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum==goal){
        //             count++;
        //         }
        //         if(sum>goal) break;
        //     }
        // }
        // return count;
        int n = nums.size();
        int sum=0;
        int ans=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
           sum+=nums[i];
           if(sum==goal) ans++;
           if(mpp.find(sum-goal)!=mpp.end()){
                ans+=mpp[sum-goal];
           }
           if(mpp.find(sum)!=mpp.end()){
                mpp[sum]++;
           }else{
                mpp[sum]=1;
           }

        }
        return ans;
        
        
    }
};