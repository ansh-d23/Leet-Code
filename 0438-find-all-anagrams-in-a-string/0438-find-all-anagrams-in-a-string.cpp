class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> vec1(26,0);
        vector<int> vec2(26,0);

        for(auto& ch : p) vec1[ch-'a']++;

        int k = p.length();
        int n = s.length();

        int i=0;
        int j=0;
        vector<int> res;

        while(j<n){

            vec2[s[j]-'a']++;

            if(j-i+1 == k){
                if(vec1==vec2){
                    res.push_back(i);
                }
                vec2[s[i]-'a']--;
                i++;
            }

            j++;
        }

        return res;
        
    }
};