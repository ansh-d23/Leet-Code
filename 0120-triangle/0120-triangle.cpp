class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int row = triangle.size();

        vector<vector<int>> dp(row,vector<int>(row));

        for(int i=0;i<row;i++){
            dp[row-1][i]=triangle[row-1][i];
        }

        for(int i=row-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diagonal);
            }
        }

        return dp[0][0];

        
    }
};