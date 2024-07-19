class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            int mini = INT_MAX;
            int index;
            bool flag = true;

            for(int j=0;j<m;j++){
                int val = matrix[i][j];

                if(val < mini){
                    mini = val;
                    index=j;
                }
            }

            //column search
            for(int row=0;row<n;row++){
                int val = matrix[row][index];
                if(val > mini){
                    flag = false;
                }   
            }

            if(flag) ans.push_back(mini);

        }

        return ans;
        
    }
};