class Solution {
    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image, int color, vector<int>& delrow, vector<int>& delcol, int inicolor) {
        ans[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != color) {
                dfs(nrow, ncol, ans, image, color, delrow, delcol, inicolor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];
        if (inicolor == color) return image;

        vector<vector<int>> ans = image;
        vector<int> delrow = {1, 0, -1, 0};
        vector<int> delcol = {0, 1, 0, -1};

        dfs(sr, sc, ans, image, color, delrow, delcol, inicolor);

        return ans;
    }
};
