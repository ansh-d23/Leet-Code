class Solution {
public:

    int binarySum(vector<int> row){
        int n= row.size();
        int sum=0;
        for(int i=n-1;i>=0;i--){
            sum += row[i] * pow(2,(n-1-i));
        }
        return sum;
    }

    int matrixScore(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        //Putting MSB as 1
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++){

                    if(grid[i][j]==0) grid[i][j]=1;
                    else 
                    if(grid[i][j]== 1) grid[i][j]=0;
                }
            }
        }

       

        //Maximizing 1bits coloumn wise

        for(int j=1;j<m;j++){
            int bit_1 = 0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1) bit_1++;
            }

            // comparing
            int bit_0 = n-bit_1;
            if(bit_0>bit_1){
                //flip
                for(int k=0;k<n;k++){
                    if(grid[k][j]==0) grid[k][j]=1;
                    else
                    if(grid[k][j]==1) grid[k][j]=0;
                }
            }

        }

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

        //calculation
        int ans=0;
        for(int i=0;i<n;i++){
            ans+= binarySum(grid[i]);
        }

        return ans;
        
    }
};