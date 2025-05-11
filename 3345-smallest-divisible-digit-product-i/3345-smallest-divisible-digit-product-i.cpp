class Solution {
public:
    int prod(int n) {
        int product = 1;
        while (n > 0) {
            int rem = n % 10;
            n = n / 10;
            product = product * rem;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        for (int i = n;; i++) {
            int prod_sum = prod(i);
            if (prod_sum % t == 0) {
                return i;
            }
        }
    }
};