class Solution {
public:
    int memo(int i, int count,int prev,vector<int>& rating, vector<vector<vector<int>>>& dp){
        int n = rating.size();
        if(count==0) return 1;
        if(i==n) return 0;
        if(prev!=-1 && dp[i][count][prev]!= -1) return dp[i][count][prev];

        int pick=0;
        if(prev==-1 || rating[i] > rating[prev]){
            pick = memo(i+1,count-1,i,rating,dp);
        }
        int not_pick = memo(i+1,count,prev,rating,dp);

        if(prev!=-1) dp[i][count][prev] = pick+not_pick;
        return pick + not_pick;
    }
    int numTeams(vector<int>& rating) {

        int n  = rating.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(n,-1)));
        vector<vector<vector<int>>> dp2(n,vector<vector<int>>(3,vector<int>(n,-1)));

        int a  = memo(0,3,-1,rating,dp);
        reverse(rating.begin(),rating.end());
        int b = memo(0,3,-1,rating,dp2);

         return a+b;
        
    }
};