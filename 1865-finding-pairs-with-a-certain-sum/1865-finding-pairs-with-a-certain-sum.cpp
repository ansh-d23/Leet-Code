class FindSumPairs {
    unordered_map<int, int> mpp;
    vector<int> n1, n2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;

        for (const auto& it : nums2) {
            mpp[it]++;
        }
    }

    void add(int index, int val) {
        int old_val = n2[index];
        int new_val = old_val + val;

        mpp[old_val]--;
        if (mpp[old_val] == 0) {
            mpp.erase(old_val);
        }

        mpp[new_val]++;
        n2[index] = new_val;
    }

    int count(int tot) {
        int ans = 0;
        for (const auto& it : n1) {
            int complement = tot - it;
            if (mpp.find(complement) != mpp.end()) {
                ans += mpp[complement];
            }
        }
        return ans;
    }
};
