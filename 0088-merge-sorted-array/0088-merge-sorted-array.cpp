class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                ans.push_back(nums2[j]);
                i++; j++;
            }else
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]); i++;
            }else{
                ans.push_back(nums2[j]); j++;
            }
        }

        for(int t=i;t<m;t++){
            ans.push_back(nums1[t]);
        }
        for(int t=j;t<n;t++){
            ans.push_back(nums2[t]);
        }
        nums1=ans;
    }
};