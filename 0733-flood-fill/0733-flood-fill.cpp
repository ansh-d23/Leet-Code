class Solution {
    void bfs(int sr, int sc, int color, vector<vector<int>>& image, vector<vector<int>>& vis, vector<vector<int>>& ans){
        vis[sr][sc]=1;

        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>> que;
        que.push({sr,sc});

        while(!que.empty()){

            int size = que.size();
            vector<int> dx = {1,0,-1,0};
            vector<int> dy = {0,1,0,-1};

            for(int i=0;i<size;i++){
                auto [sr,sc] = que.front();
                ans[sr][sc]=color;
                que.pop();

                for(int j=0;j<4;j++){
                    int nr = sr + dx[j];
                    int nc = sc + dy[j];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=1 && image[nr][nc]==image[sr][sc]){
                        vis[nr][nc]=1;
                        que.push({nr,nc});
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        //bfs
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans = image;

        bfs(sr,sc,color,image, vis, ans);

        return ans; 
    }
};