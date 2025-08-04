class Solution {
    vector<int> findlps(string s){
        int n = s.length();
        vector<int> lps(n);

        int i=1;
        int j=0;
        while(i<n){
            if(s[i]==s[j]){
                lps[i]=j+1;
                i++;
                j++; 
            }else
            if(j>0){
                j = lps[j-1];
            }else{
                lps[i]=0;
                i++;
            }
        }

        return lps;
    }

    bool kmp(string s, string goal, vector<int>& lps){
        int n = s.size();
        int m = goal.size();

        int i=0;
        int j=0;
        while(i<n){
            if(s[i]==goal[j]){
                i++;
                j++;
            }
            if(j==m) return true;
            if(i<n && s[i]!=goal[j]){
                if(j>0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return false;
    }
public:
    bool rotateString(string s, string goal) {

        // brute - o(nm)
        // KMP - o(n+m)

        int n = s.length();
        int m = goal.length();

        if(n!=m) return false;

        s+=s;
        vector<int> lps = findlps(goal);
        return kmp(s,goal,lps);
    }
};