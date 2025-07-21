class Solution {
public:
    string makeFancyString(string s) {
        
        int n = s.length();
        string ans;

        if(n==0) return "";

        ans+=s[0];

        int count=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            }else{
                count=1;
            }

            if(count<3){
                ans+=s[i];
            }
        }

        return ans;
        
    }
};