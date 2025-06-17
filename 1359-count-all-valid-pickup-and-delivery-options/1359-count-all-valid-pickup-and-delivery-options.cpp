class Solution {
    const int mod  = 1e9 + 7;
public:
    int countOrders(int n) {
        long long ans=1;

        for(int i=1;i<=n;i++){
            int choice = (i*2 - 1)*i;
            ans  = (ans%mod)*choice;
            ans=ans%mod;
        }

        return (int)ans;
    }
};