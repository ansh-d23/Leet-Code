class Solution {
public:
    int arrangeCoins(int n) {
        long double temp = (8 * static_cast<long double>(n)) + 1;
        temp = (sqrt(temp) - 1) / 2;
        return static_cast<int>(temp);
    }
};