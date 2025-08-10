class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m,1e9));
        queue<pair<int,int>> que;
        
        if(grid[0][0] != 0 || grid[n-1][m-1]!=0) return -1;
        dist[0][0]=0;
        que.push({0,0});

        vector<int> dx = {1,0,-1,0,1,1,-1,-1};
        vector<int> dy = {0,1,0,-1,1,-1,1,-1};

        while(!que.empty()){
            auto [i, j] = que.front();
            que.pop();

            for(int t=0;t<8;t++){
                int nx = i + dx[t];
                int ny = j + dy[t];

                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==0){
                    if(dist[nx][ny] > 1 + dist[i][j]){
                        dist[nx][ny] = 1 + dist[i][j];
                        que.push({nx,ny});
                    }
                }
            }
        }

        return dist[n-1][m-1]+1;
        
    }
};