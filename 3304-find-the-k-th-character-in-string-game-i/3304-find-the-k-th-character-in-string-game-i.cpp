class Solution {
public:
    char kthCharacter(int k) {

        string str="a";

        while(str.length()<k){
            int it = str.length();
            for(int i=0;i<it;i++){
                char ch = str[i];
                int temp = (ch-'a'+1)%26;
                char add = temp+'a';
                str+=add;
            }
        }

        return str[k-1];
        
    }
};