class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board){
        vis[row][col]=1;

        int direcx[] = {0, 1 , 0, -1};
        int direcy[] = {1, 0, -1, 0};

        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<4;i++){
            int nrow = row + direcx[i];
            int ncol = col + direcy[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        // row traversing
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(vis[i][n-1]==0 && board[i][n-1]=='O'){
                dfs(i,n-1,vis,board);
            }
        }

        //col traversing
        for(int i=0;i<m;i++){
            if(vis[0][i]==0 && board[0][i]=='O'){
                dfs(0,i,vis,board);
            }
            if(vis[m-1][i]==0 && board[m-1][i]=='O'){
                dfs(m-1,i,vis,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                    vis[i][j]=1;
                }
            }
        }
        
    }
};