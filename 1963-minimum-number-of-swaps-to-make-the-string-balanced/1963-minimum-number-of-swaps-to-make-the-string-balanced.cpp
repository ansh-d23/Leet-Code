class Solution {
public:
    int minSwaps(string s) {
        int maxm=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==']') count++;
            if(s[i]=='[') count--;
            maxm=max(maxm,count);
        }
        return (maxm+1) /2;
    }
};