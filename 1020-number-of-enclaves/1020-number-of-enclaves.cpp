class Solution {
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid){
        vis[i][j]=1;

        int m = grid.size();
        int n = grid[0].size();

        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};

        for(int t=0;t<4;t++){
            int nx = i + dx[t];
            int ny = j + dy[t];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1 && vis[nx][ny]==0){
                dfs(nx, ny, vis, grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    vis[i][j]=1;
                }
            }
        }

        for(int i=0;i<m;i++){
            if(vis[i][0]==0 && grid[i][0]==1){
                dfs(i,0,vis,grid);
            }
            if(vis[i][n-1]==0 && grid[i][n-1]==1){
                dfs(i,n-1,vis,grid);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[0][i] && grid[0][i]==1){
                dfs(0,i,vis,grid);
            }
            if(!vis[m-1][i] && grid[m-1][i]==1){
                dfs(m-1,i,vis,grid);
            }
        }
        
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0){
                    ans++;
                }
            }
        }

        return ans;
    }
};