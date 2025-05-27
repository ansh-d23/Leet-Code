class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = n * (n + 1) / 2;    
        int div = n / m;           
        int dm = m * div * (div + 1) / 2;

        return sum - 2 * dm;
    }
};