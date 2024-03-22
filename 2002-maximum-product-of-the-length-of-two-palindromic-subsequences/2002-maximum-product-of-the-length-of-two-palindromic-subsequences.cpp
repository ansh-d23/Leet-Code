class Solution {
public:
    int maxProduct(string s) {
        int n=s.length();
        unordered_map<int,int> mpp;
        for(int i=1;i<pow(2,n);i++){
            string s0="";
            for(int j=0;j<n;j++){
                if((i&(1<<j))){
                    s0+=s[j];
                }
            } 
            string s1 = s0;
            reverse(s1.begin(),s1.end());
            if(s1==s0){
                mpp[i]=s1.length();
            }
        }
          int maxm = -1;
        for (auto it = mpp.begin(); it != mpp.end(); ++it) {
            for (auto kt = next(it); kt != mpp.end(); ++kt) {
                int a=it->first;
                int b=kt->first;
                if ((a & b) == 0) { 
                    maxm = max(maxm, (it->second * kt->second));
                }
            }
        }
        return maxm;
    }
};