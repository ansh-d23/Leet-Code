class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        /*sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (i > 0 && nums1[i] == nums1[i - 1]) {
                i++;
                continue;
            }
            if (j > 0 && nums2[j] == nums2[j - 1]) {
                j++;
                continue;
            }
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;*/
        unordered_set<int> s1;
        vector<int> ans;
        unordered_set<int> s2;
        for(int i=0;i<nums1.size();i++) s1.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++){
            if(s1.find(nums2[i])!=s1.end()){
                s2.insert(nums2[i]);
            }
        }
       for(auto it : s2) ans.push_back(it);
       return ans;
    }
};