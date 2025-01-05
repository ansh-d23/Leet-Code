class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shift) {
        int n = s.length();
        vector<int> prefix_diff(n + 1, 0);

        for (int i = 0; i < shift.size(); i++) {
            int start = shift[i][0];
            int end = shift[i][1];
            int direc = shift[i][2];

            prefix_diff[start] += (direc == 1) ? 1 : -1;
            if (end + 1 < n) {
                prefix_diff[end + 1] -= (direc == 1) ? 1 : -1;
            }
        }

        int diff = 0;
        string ans;

        for (int i = 0; i < n; i++) {
            diff += prefix_diff[i];
            char ch = s[i];
            int shift_amount = (diff % 26 + 26) % 26;
            ch = 'a' + (ch - 'a' + shift_amount) % 26; 
            ans += ch;
        }

        return ans;
    }
};
