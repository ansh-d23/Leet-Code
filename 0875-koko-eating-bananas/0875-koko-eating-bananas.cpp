class Solution {
public:
    int findmax(vector<int>& piles){
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }

    double caclhr(vector<int>& piles, double h){
        double ans=0;
        for(int i=0;i<piles.size();i++){
            ans+= ceil((double)piles[i]/(double)h);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, double h) {
        int low=0; int high = findmax(piles);
        while(low<=high){
            int mid = (high+low)/2;
            double totalh = caclhr(piles,mid);
            if(totalh<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};