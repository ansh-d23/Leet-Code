class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        unordered_map<string, int> mpp1; 
        vector<int> ans;

        for (auto& it : words) mpp1[it]++; 

        int wordLen = words[0].size();
        int wordCount = words.size();
        int window = wordLen * wordCount;

        int n = s.length();

        for (int i = 0; i <= n - window; ++i) { 
            unordered_map<string, int> mpp2;

            for (int j = 0; j < wordCount; ++j) {
                string temp = s.substr(i + j * wordLen, wordLen);
                mpp2[temp]++;
            }

            if (mpp1 == mpp2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
