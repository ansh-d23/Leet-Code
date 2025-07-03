class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> mpp;
        vector<int> ans;
        int n = nums.size();

        for(int i=0;i<n;i++) mpp[nums[i]]=i;


        for(int i=0;i<n;i++){
            int fnd = target-nums[i];
            if(mpp.find(fnd) != mpp.end()){
                if(i!=mpp[fnd]){
                    ans.push_back(i);
                    ans.push_back(mpp[fnd]);
                    break;
                }
            }
        }

        return ans;
        
    }
};