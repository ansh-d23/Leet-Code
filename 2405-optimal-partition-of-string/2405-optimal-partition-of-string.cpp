class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> mpp;
        vector<string> ans;
        string temp;
        for(int i=0;i<s.length();i++){
            if(mpp.find(s[i])!=mpp.end()){
                ans.push_back(temp);
                temp="";
                mpp.clear();
            }
            mpp.insert(s[i]);
            temp+=s[i];
        }
        ans.push_back(temp);
        return ans.size();
    }
};