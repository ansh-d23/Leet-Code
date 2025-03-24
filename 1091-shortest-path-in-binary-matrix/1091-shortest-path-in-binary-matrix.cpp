class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        dist[0][0]=1;
        pq.push({1,{0,0}});
        int dirx[] = {0,1,0,-1,1,1,-1,-1};
        int diry[] = {1,0,-1,0,1,-1,-1,1};

        while(!pq.empty()){

            int dis = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(i==(n-1) && j==(m-1)) return dist[n-1][m-1];

            for(int it=0;it<8;it++){
                int newx = i + dirx[it];
                int newy = j + diry[it];

                if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==0){
                    if(dis + 1 < dist[newx][newy]){
                        dist[newx][newy]=dis+1;
                        pq.push({dist[newx][newy],{newx,newy}});
                    }
                }
            }

        }

        return -1;
        
    }
};