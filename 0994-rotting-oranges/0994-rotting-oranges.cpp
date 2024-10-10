class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visi(n,vector<int>(m,0));
        // {{r,c},t}
        queue<pair<pair<int,int>,int>> que;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    que.push({{i,j},0});
                    visi[i][j]=2;
                }else{
                    visi[i][j]==0;
                }
            }
        }

        int time=0;
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};

        while(!que.empty()){
            int r = que.front().first.first;
            int c = que.front().first.second;
            int t = que.front().second;

            time = max(time,t);

            que.pop();

            for(int i=0;i<4;i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visi[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    que.push({{nrow,ncol},t+1});
                    visi[nrow][ncol]=2;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visi[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }

        return time;
        
    }
};