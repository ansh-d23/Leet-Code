class Solution {
public:
    int findLucky(vector<int>& arr) {

        int n = arr.size();
        vector<int> freq(501,0);
        int ans=-1;

        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }

        for(auto& it : arr){
            if(freq[it]==it){
                ans=max(ans,it);
            }
        }

        return ans;  
    }
};