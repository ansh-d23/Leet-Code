class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;
        long long temp;
        for(int i=0;i<n;i++){
            int count=0;
            if(nums[i]==0){
                while(i<n && nums[i]==0){
                    count++;
                    i++;
                }
                if(count%2==0){
                    temp = count/2;
                    temp = temp*(count+1);
                }else{
                    temp = (count+1)/2;
                    temp = temp*count;
                }
                ans+=temp;
            }
        }
        return ans;
    }
};