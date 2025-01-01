class Solution {
public:
    int maxScore(string s) {

        int left_zero = 0;
        int right_one = 0;
        int maxm = -1;

        for(char str : s){
            if(str=='1') right_one++;
        }

        for(char str : s){
            if(str=='0') left_zero++;
            else right_one--;
            maxm = max(maxm , (left_zero + right_one));
        }

        return maxm;
        
    }
};