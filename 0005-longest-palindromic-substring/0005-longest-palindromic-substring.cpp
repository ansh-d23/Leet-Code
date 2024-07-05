class Solution {
public:
    string longestPalindrome(string s) {

        int n=s.length();
        int max_length = 0;
        int index=0;

        vector<vector<bool>> t(n,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            t[i][i]=true;
            max_length=1;
        }

        for(int l=2;l<=n;l++){
            for(int i = 0 ; i<n-l+1;i++){
                int j = i+l-1;

                if(s[i]==s[j] && l==2){
                    t[i][j]=true;
                    max_length=2;
                    index=i;
                }else 
                if(s[i]==s[j] && t[i+1][j-1]){
                    t[i][j]=true;
                    if(j-i+1 > max_length){
                        max_length = j-i+1;
                        index=i;
                    }
                }else{
                    t[i][j]=false;
                }
            }
        }
        
        return s.substr(index,max_length);
    }
};