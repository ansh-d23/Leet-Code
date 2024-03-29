class Solution {
public:
    int arrangeCoins(int n) {
        long long temp = (8*n)+1;
        temp = (sqrt(temp)-1)/2;
        return temp;
    }
};