class Solution {

void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int& p) {
    vis[i][j] = 1;

    int m = grid.size();
    int n = grid[0].size();

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    for (int it = 0; it < 4; it++) {
        int nx = i + dx[it];
        int ny = j + dy[it]; 

        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && !vis[nx][ny]) {
            dfs(nx, ny, grid, vis, p);  
        }else{
            if(nx < 0 || nx >= m || ny < 0 || ny >= n  ||  vis[nx][ny]==0){
                p++;
            }
        }
    }
}

public:
    int islandPerimeter(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        int perimeter = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(i,j,grid,vis,perimeter);
                }
            }
        }

        return perimeter;
    }
};