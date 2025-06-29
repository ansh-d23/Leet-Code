class Solution {
    int find_lcp(const string& a, const string& b) {
        int n = a.length();
        int m = b.length();
        int k = min(n, m);
        int i = 0;
        while (i < k && a[i] == b[i]) {
            i++;
        }
        return i;
    }
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        if (n <= 2) {
            return vector<int>(n, 0);
        }

        vector<int> lcp(n);
        lcp[0] = 0; 
        for (int i = 1; i < n; ++i) {
            lcp[i] = find_lcp(words[i - 1], words[i]);
        }

        vector<int> pre(n), suff(n);
        pre[0] = 0;
        for (int i = 1; i < n; ++i) {
            pre[i] = max(pre[i - 1], lcp[i]);
        }

        suff[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            suff[i] = max(suff[i + 1], lcp[i + 1]);
        }

        vector<int> ans(n);
        ans[0] = suff[1];             
        ans[n - 1] = pre[n - 2];    

        for (int i = 1; i < n - 1; ++i) {
            int skip_i = find_lcp(words[i - 1], words[i + 1]);
            ans[i] = max({pre[i - 1], suff[i + 1], skip_i});
        }

        return ans;
    }
};
