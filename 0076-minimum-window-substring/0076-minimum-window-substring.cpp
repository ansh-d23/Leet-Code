class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> mpp;
        int n = s.length();
        int k = t.size();

        for(auto& ch : t) mpp[ch]++;

        int i=0;
        int j=0;
        int count=0;
        int min_idx = 0;
        int mini=INT_MAX;

        while(j<n){

            if(mpp[s[j]] > 0) count++;
            mpp[s[j]]--;

            while(count==k){
                if(j-i+1 < mini){
                    mini = j-i+1;
                    min_idx = i;
                }

                mpp[s[i]]++;
                if(mpp[s[i]] > 0) count--;
                i++;
            }

            j++;
        }

        return mini==INT_MAX ? "" : s.substr(min_idx,mini);    
    }
};