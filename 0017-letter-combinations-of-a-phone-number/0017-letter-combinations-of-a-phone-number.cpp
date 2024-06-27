class Solution {
public:

    void backtracking(int idx,string& ds,vector<string>& ans,string digits,vector<string>& hash){

        if(idx == digits.length()){
            ans.push_back(ds);
            return;
        }

        char temp =  digits[idx];
        string letters = hash[temp - '0'];

        for(int i=0;i<letters.length();i++){
                ds += letters[i];
                backtracking(idx+1,ds,ans,digits,hash);
                ds.pop_back();
        }
    }    

    
    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if(digits.empty()) return ans;

        vector<string> hash(10);

        hash[2]="abc";hash[3]="def";
        hash[4]="ghi";hash[5]="jkl";hash[6]="mno";
        hash[7]="pqrs";hash[8]="tuv";hash[9]="wxyz";

        string ds;

        backtracking(0,ds,ans,digits,hash);
        return ans;
    }
};