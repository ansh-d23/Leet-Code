class Solution {
public:
unordered_map<char,vector<int>> mp;

bool match(string &word){
    int idx=-1;

    for(auto i:word){
        auto &cv=mp[i];
        auto nIdx=upper_bound(cv.begin(),cv.end(),idx)-cv.begin();

        if(nIdx==cv.size())
        return false;
        else{
            idx=cv[nIdx];
        }
    }

    return true;
}
    int numMatchingSubseq(string s, vector<string>& words) {
        

       int n=s.size();
       for(int i=0;i<n;i++){
           mp[s[i]].push_back(i);
       }

       int ans=0;

       for(auto &i:words){
          ans+= match(i);
       }

       return ans;
    }
};