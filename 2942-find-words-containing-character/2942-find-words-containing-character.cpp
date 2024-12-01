class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {

        vector<int> ans;
        int j=0;
        for(string s : words){
            for(int i=0;i<s.length();i++){
                if(s[i]==x){
                    ans.push_back(j);
                    break;
                }
            }
            j++;
        }

        return ans;        
    }
};