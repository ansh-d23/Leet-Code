class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {

        int n = s.length();
        vector<string> ans;

        int rem = n%k;
        int chToFill;
        if(rem==0){
            chToFill=0;
        }else{
            chToFill = k-rem;
        }


        for(int i=0;i<chToFill;i++){
            s+=fill;
        }

        n = s.length();

        for(int i=0;i<n-k+1;i+=k){
            string temp = s.substr(i,k);
            ans.push_back(temp);
        }

        return ans;   
    }
};