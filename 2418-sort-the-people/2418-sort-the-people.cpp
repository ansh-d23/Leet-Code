class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        int n = names.size();
        vector<pair<int,string>> temp;
        vector<string> ans;

        for(int i=0;i<n;i++){
            temp.push_back({heights[i],names[i]});
        }

        sort(temp.rbegin(),temp.rend());

        for(int i=0;i<n;i++){
            string val = temp[i].second;
            ans.push_back(val);
        }

        return ans;
        
    }
};