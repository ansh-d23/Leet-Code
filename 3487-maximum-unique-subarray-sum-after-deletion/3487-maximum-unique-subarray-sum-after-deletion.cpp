class Solution {
public:
    int maxSum(vector<int>& nums) {

        int n = nums.size();
        int sum=0;
        int maxm=0;

        unordered_set<int> stt;

        for(int i=0;i<n;i++){
            if(sum+nums[i] > maxm){
                if(stt.find(nums[i]) == stt.end()){
                    sum+=nums[i];
                    stt.insert(nums[i]);
                    maxm = max(maxm,sum);
                }
            }
        }

        return sum;
        
    }
};