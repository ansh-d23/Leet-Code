class Solution {
    int count(string s, string sub){
        int i=0;
        int j=0;

        int m = sub.size();
        int ans=0;

        while(i<s.size()){
            if(s[i]==sub[j]){
                j++;
                if(j==m){
                    j=0;
                    ans++;
                }
            }
            i++;
        }

        return ans;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {

        int n = s.length();

        vector<int> freq(26,0);
        for(int i=0;i<n;i++) freq[s[i]-'a']++;

        //bfs
        string curr = "";
        queue<string> q;
        q.push(curr);
        string res;

        while(!q.empty()){
            curr = q.front();
            q.pop();

            string next = curr;
            for(char ch='a';ch<='z';ch++){
                if(freq[ch-'a']<k) continue;
                next.push_back(ch);

                if(count(s,next)>=k){
                    res=next;
                    q.push(next);
                }

                next.pop_back();
            }
        }

        return res;
        
    }
};