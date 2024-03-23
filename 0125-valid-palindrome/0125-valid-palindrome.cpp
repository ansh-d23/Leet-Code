class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for(int i=0;i<s.length();i++){
            int temp=s[i];
            if((temp>='a' && temp<='z') || (temp>='A' && temp<='Z')  || (temp>='0' && temp<='9')){
                if(temp>='A' && temp<='Z'){
                    temp+=32;
                }
                char r = temp;
                res+=r;
            }
        }
        cout<<res;

        int left=0;
        int right=res.length()-1;
        while(left<=right){
            if(res[left]!=res[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};