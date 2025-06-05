class Solution {

    // finding ultimate parent
    int find(vector<int>& mpp, int v){
        if(mpp[v]==-1) return v;
        mpp[v] = find(mpp, mpp[v]);
        return mpp[v];
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {

        vector<int> mpp(26,-1);

        //building disjoint set
        int n = s1.length();
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]) continue;

            int px = find(mpp, s1[i]-'a');
            int py = find(mpp, s2[i]-'a');

            if(px==py) continue;

            if(px>py) mpp[px] = py;
            else mpp[py] = px;
        }

        string res;
        int m = baseStr.length();
        for(int i=0;i<m;i++){
            int parent = find(mpp, baseStr[i]-'a');
            res.push_back(char(parent+97));
        }

        return res; 
    }
};