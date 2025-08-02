class Solution {

    pair<int,int> max_element(vector<vector<int>>& mat,int mid){
        int n = mat.size();
        int m = mat[0].size();

        pair<int,int> res;

        int maxm= mat[0][mid];
        int i=0;
        int j=mid;

        for(int k=0;k<n;k++){
            if(mat[k][mid] > maxm){
                maxm = mat[k][mid];
                i=k;
                j=mid;
            }
        }

        return {i,j};
    }

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int low=0;
        int high=m-1;

        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};

        while(low<=high){
            int mid = low + (high-low)/2;

            auto [i,j] = max_element(mat,mid);

            int q = j;
            for(int k=0;k<4;k++){
                int ndx = i+dx[k];
                int ndy = j+dy[k];
                if(ndx>=0 && ndx<n && ndy>=0 && ndy<m){
                    if(mat[ndx][ndy] > mat[i][j]){
                        q = ndy;
                    }
                }
            }

            if(q==j) return {i,j};
            
            if(q > j){
                low=mid+1;
            }else{
                high=mid-1;
            }

        }

        return {0,0};
        
    }
};