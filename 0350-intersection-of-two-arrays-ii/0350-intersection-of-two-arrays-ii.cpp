class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int>  mpp1;
        unordered_map<int,int> mpp2;
        vector<int> ans;

        for(int i=0;i<nums1.size();i++) mpp1[nums1[i]]++;
        for(int i=0;i<nums2.size();i++) mpp2[nums2[i]]++;

            for(auto it2 : mpp2){
                if(mpp1.find(it2.first) != mpp1.end()){
                    auto it1  = mpp1.find(it2.first);
                    int temp = min(it1->second,it2.second);

                    for(int i=0;i<temp;i++) ans.push_back(it2.first);
                }
            }
            

        return ans;
        
    }
};