class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<pair<int,int>> arr;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto it : mpp){
            arr.push_back({it.second,it.first});
        }

        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second > b.second; 
            return a.first < b.first; 
        });

        vector<int> ans;

        for(auto val : arr){
            int m = val.first;
            for(int i=0;i<m;i++) ans.push_back(val.second);
        }

        return ans;
        
    }
};