class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count = 0;
        unordered_set<char> set;
        for(char ch: s) set.insert(ch);
        for(char ch: set){
            int first = s.find(ch);
            int last = s.rfind(ch);

            if(last>first){
                unordered_set<char> uni;
                for(int i=first+1;i<last;i++){
                    uni.insert(s[i]);
                }
                count+=uni.size();
            }

        }
        return count;
    }
};