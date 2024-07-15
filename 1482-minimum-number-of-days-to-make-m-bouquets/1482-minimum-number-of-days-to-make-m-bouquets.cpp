class Solution {
public:
    int avg_m(vector<int>& bloomDay,int mid,int k){
        int n = bloomDay.size();
        int consicutive = 0;
        int ans=0;

        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                consicutive++;
            }else consicutive=0;

            if(consicutive==k){
                ans++;
                consicutive=0;
            }
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long total_flower = (long long)k*m;
        if( total_flower > n) return -1;

        int low= 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;

        while(low<=high){
            int mid = low+ (high-low)/2;

            int val = avg_m(bloomDay,mid,k);

            if(val>=m){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;
        
    }
};