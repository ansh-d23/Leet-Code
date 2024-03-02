class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int k=0;
        for(int i=0;i<spaces.size();i++){
            string temp = s.substr(k,spaces[i]-k);
            ans+=temp;
            ans+=" ";
            k=spaces[i];
            cout<<temp<<endl;
        }
        ans+=s.substr(k);
        return ans;
    }
};