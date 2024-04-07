class Solution {
public:
    bool checkValidString(string s) {
        bool p_left=false;
        int count=0,countl=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                p_left=true;
                countl++;
            }
            if(s[i]=='*') count++;
            if(s[i]==')'){
                if(p_left){
                    if(countl>1){
                        countl--;
                    }else{
                        countl--;
                        p_left=false;
                    }
                }
                else{
                    count--;   
                }
            }
        }
        if(count>=countl) return true;
        if(p_left || count<0){
            return false;
        }
        return true;
    }
};