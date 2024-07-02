class Solution {
public:
    
    int recurr(int i,int n){
        if(i==n) return 1;
        if(i>=n) return 0;

        int left = recurr(i+1,n);
        int right = recurr(i+2,n);

        return left+right;
    }

    int climbStairs(int n) {
        return recurr(0,n);
    }
};