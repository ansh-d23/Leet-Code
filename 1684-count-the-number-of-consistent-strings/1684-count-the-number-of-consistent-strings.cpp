class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        unordered_set<char> stt;

        for(char c : allowed){
            stt.insert(c);
        }

        int ans=words.size();
        for(string s : words){
            for(int i=0;i<s.length();i++){
                if(stt.find(s[i]) == stt.end()){
                    ans--;
                    break;
                }
            }
        }

        return ans;

    }
};