class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        int unmatched = 0;

        int i=0,j=0;

        if(n!=m) return false;

        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                unmatched++;
            }
        }

        return unmatched<3 ? true : false;
        
    }
};