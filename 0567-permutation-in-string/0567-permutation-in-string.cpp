class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> v1(26,0);
        vector<int> v2(26,0);

        int k = s1.length();
        int n = s2.length();

        int i=0;
        int j=0;

        for(auto& ch : s1) v1[ch-'a']++;

        while(j<n){
            v2[s2[j]-'a']++;

            if(j-i+1 == k){
                if(v1 == v2) return true;
                v2[s2[i]-'a']--;
                i++;
            }
            j++;
        }

        return false;
        
    }
};