class Solution {
public:
    int countSeniors(vector<string>& details) {

        int ans=0;
        int n = details.size();

        for(int i=0;i<n;i++){
            string  s = details[i];
            string temp = s.substr(11,2);
            int val = stoi(temp);
            if(val > 60) ans++;
        }
        
        return ans;
    }
};