class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        bool firstone=false;
        int n=s.length()-1;
        int k=0;
        int p=0;
        for(int i=n;i>=p;i--){
            if(s[i]=='1' && firstone==false){
                swap(s[n],s[i]);
                firstone=true;
            }else
            if(s[i]=='1'){
                cout<<s[i]<<" "<<s[k];
                swap(s[i],s[k]);
                k++; p++;
                i++;
            }
        }
        return s;
    }
};