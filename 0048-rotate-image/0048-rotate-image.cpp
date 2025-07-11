class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // this code was not optimized in terms of space complexity

       /* int n=matrix.size();
        vector<vector<int>> temp;
        for(int j=0;j<n;j++){
            vector<int> row;
            for(int i=n-1;i>=0;i--){
                row.push_back(matrix[i][j]);
            }
            temp.push_back(row);
        }

        matrix=temp; */ 

        // #optimized code 
        
        int n = matrix.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};