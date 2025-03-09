class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {

        int n = colors.size();
        int ans = 0;
        int curr_cnt = 1;

        if(k>n) return 0;

        for(int i=0;i<=n+k-3;i++){

            if(colors[i%n] != colors[(i+1)%n]){
                curr_cnt++;
                if(curr_cnt>=k){
                    ans++;
                } 
            }else{
                curr_cnt=1;
            }
        }

        return ans;
        
    }
};