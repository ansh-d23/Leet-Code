class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mpp1;
        unordered_map<char,char> mpp2;
        if(s.length() != t.length()) return false;
        for(int i=0;i<s.length();i++){
            if(mpp1.find(s[i]) == mpp1.end()){
                mpp1.insert({s[i],t[i]});
            }else{
                if(mpp1.find(s[i])->second != t[i]) return false;
            }
        }

        for(int i=0;i<t.length();i++){
            if(mpp2.find(t[i]) == mpp2.end()){
                mpp2.insert({t[i],s[i]});
            }else{
                if(mpp2.find(t[i])->second != s[i]) return false;
            }
        }

        return true;
    }
};