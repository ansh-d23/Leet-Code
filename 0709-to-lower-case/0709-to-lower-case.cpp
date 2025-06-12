class Solution {
public:
    string toLowerCase(string s) {

        string ans;

        for(auto ch : s){
            if(ch>='A' && ch<='Z'){
                int temp = ch + 32;
                char var = temp;
                ans+=var;
            }else{
                ans+=ch;
            }
        }

        return ans;
        
    }
};