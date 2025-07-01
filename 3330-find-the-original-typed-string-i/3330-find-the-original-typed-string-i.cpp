class Solution {
public:
    int possibleStringCount(string word) {

        int n = word.length();
        int count=1;
        int mul=0;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]){
                mul++;
            }
            else{
                count+=mul;
                mul=0;
            }
        }

        count+=mul;

        return count;
        
    }
};