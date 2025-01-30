class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int,int> first,last,count;
        int n = nums.size();
        int maxm = INT_MIN;
        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            if(first.find(nums[i]) == first.end()){
                first[nums[i]]=i;
            }
            last[nums[i]] = i;
            count[nums[i]]++; 
            maxm = max(maxm,count[nums[i]]);          
        }

        for(auto& [num,count] : count){
            if(count==maxm){
                ans = min(ans, last[num]-first[num]+1);
            }
        }

        return ans;
        
    }
};