class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {

        vector<string> ans;
        int n = words.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=i){
                    int m = words[j].length();
                    int q = words[i].length();
                    if(m>=q && words[j].find(words[i]) != string::npos){
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }

        }

        return ans;
        
    }
};