class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){

            temp.push_back(nums[i]);

            if((i+1)%3==0){
                int last = nums[i];
                int start = nums[i-2];

                if(last-start <= k){
                    ans.push_back(temp);
                    temp.clear();
                }else{
                    ans.clear();
                    break;
                }
            }
        }

        return ans;
        
    }
};