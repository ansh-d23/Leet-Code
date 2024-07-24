class Solution {
public:
    int getval(int n, vector<int>& mpp){

        if(n<10){
            return mpp[n];
        }
        
        int ans=0;
        int placeVal = 1;

        while(n){
            int lastdigi = n%10;
            int mappdigi = mpp[lastdigi];
            ans += (mappdigi * placeVal);

            placeVal *=10;
            n/=10;
        }

        return ans;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        int n = nums.size();
        vector<pair<int,int>> arr;

        for(int i=0;i<n;i++){
            int new_val = getval(nums[i],mapping);
            arr.push_back({new_val,i});
        }

        sort(arr.begin(),arr.end());

        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(nums[arr[i].second]);
        }

        return ans;
    }
};