class Solution {
public:

    bool Isvalid(string temp){ 

        if(temp.empty() || temp.length() > 3) return false;

        if(temp[0]=='0' && temp.length()>1) return false;

        for(char ch : temp){
            if(!isdigit(ch)) return false;
        }

        int val = stoi(temp);

        if(val >= 0 && val <= 255) return true;
        return false;
    }

    void backtracking(int idx, string& s,string ds,int parts,vector<string>& ans){

        if(idx==s.length() && parts==4){
            ans.push_back(ds.substr(0,ds.length()-1));
            return;
        }

        if(parts>4) return;

        for(int i = 1; i <= 3; i++){
            if(idx + i <= s.length() && Isvalid(s.substr(idx, i))){
                backtracking(idx + i, s, ds + s.substr(idx, i) + ".", parts + 1, ans);
            }
        }

    }

    vector<string> restoreIpAddresses(string s) {

        vector<string> ans;

        string ds;
        int parts=0;

        if(s.length()>12) return ans;

        backtracking(0,s,ds,parts,ans);

        return ans;


        
    }
};