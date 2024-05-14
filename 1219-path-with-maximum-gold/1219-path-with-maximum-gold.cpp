class Solution {
public:

    int recSum(vector<vector<int>>& grid , int i , int j, vector<vector<bool>>& visited){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || grid[i][j] == 0)
            return 0;

        visited[i][j] = true;

        int a = recSum(grid, i+1, j, visited);
        int b = recSum(grid, i, j+1, visited);
        int c = recSum(grid, i-1, j, visited);
        int d = recSum(grid, i, j-1, visited);

        visited[i][j] = false;

        return grid[i][j] + max({a, b, c, d});
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxm = 0;

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    maxm = max(maxm, recSum(grid, i, j, visited));
                }
            }
        }

        return maxm;
    }
};
