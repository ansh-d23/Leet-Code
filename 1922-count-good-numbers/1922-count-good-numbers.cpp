class Solution {
public:

    const int mod = 1e9 +7;

    long long power(int x , long long n){
        if(n==0) return 1;
        if(n==1) return x%mod;

        long long temp = power(x,n/2);
        temp = (temp*temp)%mod;
    

        if(n%2==0){
            return temp;
        }else{
            return (x * temp)%mod;
        }

    }

    int countGoodNumbers(long long n) {

        if (n==1) return 5;

        if(n%2==0){
            return power(20,n/2)%mod;
        }else{
            return (5 * power(20, (n - 1) / 2)) % mod;
        }
        
    }
};