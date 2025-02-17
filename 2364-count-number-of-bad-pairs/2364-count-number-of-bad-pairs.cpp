class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        int badCount=0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((j-i) != nums[j]-nums[i]){
                    badCount++;
                }
            }
        }
        
        return badCount;
    }
};