class Solution {
public:
    string makeGood(string s) {
        int n=s.length();
        int i=0;
        while(i<(n-1)){
            if(abs(s[i]-s[i+1])==32){
                string sub = s.substr(0,i);
                string sub1 = s.substr(i+2);
                s=sub+sub1;
                i=0;
                n=s.length();
            }else{
                i++;
            }
        }
        return s;
    }
};