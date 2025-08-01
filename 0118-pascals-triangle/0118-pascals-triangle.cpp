class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i=0;i<numRows;i++){
            vector<int> rows;
            int k=0;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    rows.push_back(1);
                }else{
                    rows.push_back(ans[i-1][k] + ans[i-1][k+1]);
                    k++;
                }
            }
            ans.push_back(rows);
        }
        return ans;
    }
};