class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> mpp;
        vector<pair<int,char>> res;

        for(auto& it : s){
            mpp[it]++;
        }

        for(auto& [u,v] : mpp){
            res.push_back({v,u});
        }

        sort(res.rbegin(),res.rend());
        string ans;

        for(auto& [val,ch] : res){
            for(int i=0;i<val;i++){
                ans+=ch;
            }
        }

        return ans;
    }
};