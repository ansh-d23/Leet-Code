class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string res = "";

        for(int i=0;i<strs[0].size();i++){
            char ch = strs[0][i];
            for(string& s : strs){
                if(i==s.size() || ch != s[i]){
                    return res;
                }
            }
            res+=ch;
        }

        return res;
        
    }
};