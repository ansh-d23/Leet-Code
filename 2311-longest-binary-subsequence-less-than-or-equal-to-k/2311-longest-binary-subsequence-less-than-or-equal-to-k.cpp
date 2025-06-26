class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;    
        int power = 1;   
        long long value = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                count++;
            } else {
                if (power <= k && value + power <= k) {
                    value += power;
                    count++;
                }
            }
            if (power <= k) power *= 2;
        }

        return count;
    }
};
