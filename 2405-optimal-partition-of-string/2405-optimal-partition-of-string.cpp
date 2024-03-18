class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> mpp;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(mpp.find(s[i])!=mpp.end()){
                count++;
                mpp.clear();
            }
            mpp.insert(s[i]);
        }
        return count+1;
    }
};