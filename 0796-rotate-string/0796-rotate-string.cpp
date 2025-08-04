class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();

        if (n != m) return false;

        string temp = "";
        int j = 0;

        while (j < 2 * n) {
            temp += s[j % n];

            if (temp.length() > m) {
                for (int k = 1; k < temp.length(); ++k) {
                    temp[k - 1] = temp[k];
                }
                temp.pop_back();
            }

            if (temp == goal) return true;
            j++;
        }

        return false;
    }
};
