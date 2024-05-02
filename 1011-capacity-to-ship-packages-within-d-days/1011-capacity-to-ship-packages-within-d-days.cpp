#include <vector>
using namespace std;

class Solution {
public:
    int  obvDays(vector<int>& weight,int mid){
        int count=1;
        int sum=0,sumMax=0; 
        for(int i=0;i<weight.size();i++){
            sum+=weight[i];
            sumMax=max(sum,sumMax);
            if(sum>mid){
                count++;
                sum=weight[i]; 
            }    
        }
        return count;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start=weights[0],end=0;
        for(int i=0;i<weights.size();i++){
            start=max(start,weights[i]);
            end+=weights[i];
        }
        int ans;
        while(start<=end){
            int mid = start + (end-start)/2;
            int get_days = obvDays(weights,mid);
            if(get_days<days) end=mid-1;
            else if(get_days>days) start=mid+1;
            else return mid; 
        }
        return start; 
    }
};
