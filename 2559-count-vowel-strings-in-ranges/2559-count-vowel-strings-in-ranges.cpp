class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int m = words.size();
        vector<int> temp(m,0);

        for(int i=0;i<m;i++){
            int n = words[i].length()-1;
            string s = words[i];
            if(s[0]=='a' || s[0]=='i' || s[0]=='o' || s[0]=='u' || s[0]=='e'){
                if(s[n]=='a' || s[n]=='i' || s[n]=='o' || s[n]=='u' || s[n]=='e'){
                    temp[i]=1;
                }
            }
        }

        for(int i=1;i<temp.size();i++){
            temp[i]+=temp[i-1];
        }

        for (int i = 0; i < queries.size(); i++) {
            vector<int> lim = queries[i];
            int left = lim[0];
            int right = lim[1];
      
            int val = temp[right] - (left > 0 ? temp[left - 1] : 0);
            ans.push_back(val);
        }

        return ans;
    }
};