class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        string ans;
        vector<unordered_set<string>> remove_dup;

        for(auto& it : responses){
            unordered_set<string> temp;
            for(string s : it){
                temp.insert(s);
            }
            remove_dup.push_back(temp);
        }

        map<string,int> mpp;

        for(auto it : remove_dup){
            for(string s : it){
                mpp[s]++;
            }
        }

        int maxm = INT_MIN;

        for(auto it : mpp){
            string s = it.first;
            int val = it.second;
            if(val>maxm){
                ans=s;
                maxm=val;
            }
        }

        return ans;


    }
};