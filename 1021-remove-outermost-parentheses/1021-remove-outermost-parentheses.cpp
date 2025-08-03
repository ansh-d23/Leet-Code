class Solution {
public:
    string removeOuterParentheses(string s) {

        int count=0;
        string res;
        string temp;

        for(auto& ch : s){
            if(ch=='('){
                count++;
                temp+=ch;
            }else{
                count--;
                temp+=ch;
            }

            if(count==0){
                int n = temp.length();
                string add = temp.substr(1,n-2);
                res+=add;
                temp.clear();
            }
        }

        return res;
        
    }
};