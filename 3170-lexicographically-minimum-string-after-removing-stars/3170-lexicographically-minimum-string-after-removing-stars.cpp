class Solution {
    struct lamda{
        bool operator()(pair<char,int>& a, pair<char,int>& b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        }
    };
public:
    string clearStars(string s) {
        int n = s.length();

        priority_queue<pair<char,int>, vector<pair<char,int>>, lamda> pq;

        vector<bool> remove(n,false);
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                pq.push({s[i],i});
            }else if(!pq.empty() && s[i]=='*'){
                remove[pq.top().second] = true;
                pq.pop();
            }
        }

        string ans;
        for(int i=0;i<n;i++){
            if(s[i]!='*' && remove[i]==false){
                ans+=s[i];
            }
        }

        return ans;
    }
};