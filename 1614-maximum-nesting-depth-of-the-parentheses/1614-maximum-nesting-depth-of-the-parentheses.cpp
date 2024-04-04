class Solution {
public:
    int maxDepth(string s) {
        stack<int> ans;
        int maxi=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                count++;
            }else if(s[i]==')'){
                count--;
            }
            maxi=max(maxi,count);
        }
        return maxi;

    }
};