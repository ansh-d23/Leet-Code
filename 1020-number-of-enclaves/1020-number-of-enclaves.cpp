class Solution {
public:
    void dfs(int row,int col, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[row][col] = 1;

        int direcx[] = {1, 0, -1, 0};
        int direcy[] = {0, 1, 0, -1};

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<4;i++){
            int nrow = row + direcx[i];
            int ncol = col + direcy[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1 ){
                dfs(nrow, ncol, vis, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int count = 0;

        //top and bottom row traversing
        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i]==1) dfs(0,i,vis,grid);
            if(!vis[n-1][i] && grid[n-1][i]==1) dfs(n-1,i,vis,grid);
        }

        //top and last col traversing
        for(int j=0;j<n;j++){
            if(!vis[j][0] && grid[j][0]==1) dfs(j,0,vis,grid);
            if(!vis[j][m-1] && grid[j][m-1]==1) dfs(j,m-1,vis,grid);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }

        return count;
    }
};