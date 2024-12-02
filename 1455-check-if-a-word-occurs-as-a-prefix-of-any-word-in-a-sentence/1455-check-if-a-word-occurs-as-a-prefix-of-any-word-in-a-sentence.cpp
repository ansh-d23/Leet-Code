class Solution {
public:
    int isPrefixOfWord(string sentence, string w) {
        
        vector<string> arr;
        int n = sentence.size();
        string ans;

        for (int i = 0; i <= n; i++) {
            if (i == n || sentence[i] == ' ') { 
                arr.push_back(ans);
                ans = "";
            } else {
                ans += sentence[i];
            }
        }

        int index = 0;
        for (string s : arr) {
            index++;
            int k = s.size();
            int l = w.size();

            if (k >= l) {
                bool flag = true;
                for (int i = 0; i < l; i++) { 
                    if (w[i] != s[i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return index; 
            }
        }

        return -1; 
    }
};
