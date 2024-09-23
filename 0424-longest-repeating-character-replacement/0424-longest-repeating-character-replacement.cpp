class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        unordered_map<char,int> mpp;
        int maxx = 0;
        int count = 0;
        while(right < s.length()) {
            mpp[s[right]]++;
            maxx = max(maxx, mpp[s[right]]);
            int length = right - left + 1;
            if(length - maxx <= k) {
                count = max(count, length); 
            } else {
                mpp[s[left]]--;
                left++;
            }
            right++;
        }
        return count;
    }
};
