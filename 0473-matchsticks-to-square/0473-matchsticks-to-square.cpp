class Solution {
public:
    bool dfs(int idx, vector<int>& sides, vector<int>& matchsticks, int target) {
    
        if(idx==matchsticks.size()){
            if(sides[0]==sides[1] && sides[1]==sides[2] && sides[2]==sides[3]) return true;
            return false;
        }

        for(int i=0;i<4;i++){
            if(sides[i]+matchsticks[idx]<=target){
                sides[i]+=matchsticks[idx];
                if(dfs(idx+1,sides,matchsticks,target)) return true;
                sides[i]-=matchsticks[idx];
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        int sum = 0;
        for (int i = 0; i < matchsticks.size(); ++i) sum += matchsticks[i];
        
        if (sum % 4 != 0) return false;

        int target = sum / 4;
        vector<int> sides(4, 0);

        sort(matchsticks.rbegin(), matchsticks.rend());

        return dfs(0, sides, matchsticks, target);
    }
};
