class Solution {

    int to_int(vector<int>& nums){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans = ans*10 + nums[i];
        }
        return ans;
    }

    int super(int a, int n,int mod){

        int ans = 1;

        while(n>0){
            if(n%2==0){
                a = ((a%mod)*(a%mod))%mod;
                n/=2;
            }else{
                ans = ((ans%mod)*(a%mod))%mod;
                n--;
            }
        }

        return ans;

    }

public:
    int superPow(int a, vector<int>& b) {
        
        int mod = 1337;
        int valb = to_int(b);

        return super(a,valb,mod);
    }
};