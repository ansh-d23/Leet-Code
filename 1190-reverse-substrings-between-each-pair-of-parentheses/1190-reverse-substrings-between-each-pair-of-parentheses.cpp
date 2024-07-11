class Solution {
public:
    string reverseParentheses(string s) {

        string ans;
        stack<int> stk;
        int count=0;

        for(auto it : s){
            if(it == '('){
                stk.push(count);
            }else if(it==')'){
                //code
                int start = stk.top();
                reverse(ans.begin()+start , ans.begin()+count);
                stk.pop();
            }else{
                ans+=it;
                count++;
            }

        }

        return ans;
        
    }
};