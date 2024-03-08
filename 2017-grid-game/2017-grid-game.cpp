class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> pre(n,grid[0][0]);
        vector<long long> post(n,grid[1][n-1]);

        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+grid[0][i];
        }
        for(int i=n-2;i>=0;i--){
            post[i] = post[i+1]+grid[1][i];
        }
        long long res= LONG_MAX;
        for(int i=0;i<n;i++){
            /*int temp=post[i]+pre[i];
            if(temp>res){
                res=temp;
                ans = max(post[0]-post[i],pre[n-1]-pre[i]);
            }*/
            res = min(res,max(post[0]-post[i],pre[n-1] - pre[i]));
        }
        return res;
    }
};