class Solution {
public:
    int numberOfSubstrings(string s) {

    int n = s.length();
    vector<int> last_seen(3);

    last_seen[0]=-1;
    last_seen[1]=-1;
    last_seen[2]=-1;

    int ans=0;

    for(int i=0;i<n;i++){

        last_seen[s[i] - 'a'] = i;

        if(last_seen[0] != -1 && last_seen[1] != -1 && last_seen[2] != -1){
            ans += 1 + min({last_seen[0],last_seen[1],last_seen[2]});
        }
    }

    return ans;
        
    }
};