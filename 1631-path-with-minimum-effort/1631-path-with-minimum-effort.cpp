class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> eff(n, vector<int>(m,INT_MAX));

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        eff[0][0]=0;
        pq.push({0,{0,0}});

        vector<int> dirx = {0,1,0,-1};
        vector<int> diry = {1,0,-1,0};

        while(!pq.empty()){
            auto it = pq.top();
            int maxeff = it.first;
            int i = it.second.first;
            int j = it.second.second;
            pq.pop();

            for(int k=0;k<4;k++){
                int nx = i + dirx[k];
                int ny = j + diry[k];

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int max_diff = max(abs(heights[nx][ny]-heights[i][j]),maxeff) ;
                    if(max_diff < eff[nx][ny]){
                        eff[nx][ny] = max_diff;
                        pq.push({max_diff,{nx,ny}});
                    }  
                }
            }
        }

        return eff[n-1][m-1];
        
    }
};