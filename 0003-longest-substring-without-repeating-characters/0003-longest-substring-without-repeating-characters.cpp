class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        unordered_set<char> stt;

        int max_element=0;

        int i=0;
        int j=0;

        while(j<n){

             if(stt.find(s[j]) != stt.end()){
                stt.erase(s[i]);
                i++;
             }else{
                stt.insert(s[j]);
                max_element = max(max_element,j-i+1);
                j++;
             }

        }

        return max_element;  
    }
};