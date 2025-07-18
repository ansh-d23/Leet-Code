#include <vector>
using namespace std;

class Solution {
public:

    void merge(vector<int>& nums,int low,int mid,int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }

    int countpairs(vector<int>& nums,int low,int mid,int high){
        int right=mid+1;
        int count=0;
        for(int i=low;i<=mid;i++){
            while(right<=high && nums[i]> 2LL*nums[right]){
                right++;
            }
            count+= (right-(mid+1));
        }
        return count;
    }


    int mergesort(vector<int>& nums , int low , int high){
        int count=0;
        if(low < high) {
            int mid = low + (high-low)/2;
            count += mergesort(nums,low,mid);
            count += mergesort(nums,mid+1,high);
            count += countpairs(nums,low,mid,high);
            merge(nums,low,mid,high);
        }
        return count;
    }

    int reversePairs(vector<int>& nums) {
        // not suitable for larger arrays 

         /* int pair=0;
        //iteration
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                double t = nums[i]/2.0;
                if(nums[j] <  ceil(t)){
                    pair++;
                }
            }
        }
        return pair; */
        return mergesort(nums,0,nums.size()-1);  
    }
};
