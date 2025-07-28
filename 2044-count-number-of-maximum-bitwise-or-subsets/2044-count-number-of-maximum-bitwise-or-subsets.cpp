class Solution {
    int calc(vector<int>& arr){
        int ans=0;
        for(int it : arr){
            ans|=it;
        }
        return ans;
    }

    void bcktrack(int i,int n, vector<int>& nums, int& count, vector<int>& arr, int maxm){
        if(i==n){
            return;
        }

        arr.push_back(nums[i]);
        if(calc(arr)==maxm){
            count++;
        }
        
        //pick
        bcktrack(i+1,n,nums,count,arr,maxm);
        arr.pop_back();

        //not-pick
        bcktrack(i+1,n,nums,count,arr,maxm);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {

        int n = nums.size();
        int count=0;
        vector<int> arr;
        int maxm=0;

        for(auto it : nums){
            maxm|=it;
        }

        bcktrack(0,n,nums,count,arr,maxm);

        return count;
    }
};