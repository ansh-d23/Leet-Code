class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {

        int count_ops=0;
        long long val = k;

        while(val > 1){
            int jumps = ceil(log2(val));
            val -= pow(2,jumps-1);
            count_ops += op[jumps-1];
        }

        return 'a' + (count_ops%26);
        
    }
};