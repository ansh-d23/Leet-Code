class Solution {
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
    vis[i][j] = 1;

    int m = grid.size();
    int n = grid[0].size();

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    int count = 0;
    for (int it = 0; it < 4; it++) {
        int nx = i + dx[it];
        int ny = j + dy[it];  // ✅ FIXED

        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && !vis[nx][ny]) {
            count += dfs(nx, ny, grid, vis);  // ✅ FIXED
        }
    }

    return 1 + count;
}

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        int maxarea = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int count = dfs(i,j,grid,vis);
                    maxarea = max(maxarea,count);
                }
            }
        }

        return maxarea;
        
    }
};