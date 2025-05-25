class Solution {
public:
    int longestPalindrome(vector<string>& words) {

        unordered_map<string,int> mpp;
        int result=0;

        for(string s : words){
            string reverse = s;
            swap(reverse[0],reverse[1]);

            if(mpp[reverse] > 0){
                result+=4;
                mpp[reverse]--;
            }else{
                mpp[s]++;
            }
        }

        for(auto &it : mpp){
            string word = it.first;
            int count = it.second;
            if(word[0]==word[1] && count>0){
                result+=2;
                break;
            }
        }

        return result;
        
    }
};