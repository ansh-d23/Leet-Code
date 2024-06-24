class Solution {
public:

    bool palindrome(string &s){

        int start = 0;
        int end = s.length()-1;

        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }

        return true;
    }

    void backtracking(int index,vector<vector<string>>& ans, vector<string>& ds,string &s){

        if(index == s.length()){
            ans.push_back(ds);
            return;
        }

        for(int i=index;i<s.length();i++){

            string temp = s.substr(index,i-index+1);

            if(palindrome(temp)){
                ds.push_back(temp);
                backtracking(i+1,ans,ds,s);
                ds.pop_back();
            }

        }

    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> ds;
        backtracking(0,ans,ds,s);

        return ans;
        
    }
};