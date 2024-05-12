class Solution {
public:
    int calc_h(vector<int> piles,double mid){
        int ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=(piles[i]+mid-1)/mid; // ceil value
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
         sort(piles.begin(),piles.end());
         int start=1;
         int end=piles[piles.size()-1];
         while(start<end){
            int mid= start+ (end-start)/2;
            int expected_h = calc_h(piles,mid);
            if(expected_h>h) start=mid+1;
            else end=mid;
         }
         return start;
    }
};