class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> mpp;
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            int index=0;
            if(i == nums2.size()-1) mpp.insert({nums2[i],-1}); 
            for(int j=i+1;j<nums2.size();j++){
                if(nums2[j]>nums2[i]){
                    index=j;
                    break;
                }
            }
            if(index!=0) mpp.insert({nums2[i],nums2[index]});
            else mpp.insert({nums2[i],-1});
        }


        for(int i=0;i<nums1.size();i++){
            ans.push_back(mpp.find(nums1[i])->second);
        }
        return ans;
    }
};