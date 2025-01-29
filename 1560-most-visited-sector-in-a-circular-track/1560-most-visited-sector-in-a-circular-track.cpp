class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {

        vector<int> hash(n+1,0);
        vector<int> ans;
        int size = rounds.size();

        hash[rounds[0]]++;

        for(int i=1;i<size;i++){
            int start = rounds[i-1];
            int end = rounds[i];

            while(start != end){
                start = (start%n) +1;
                hash[start]++;
            }
        }

        int maxm= *max_element(hash.begin(),hash.end());

        for(int i=1;i<=n;i++){
            if(hash[i]==maxm) ans.push_back(i);
        }

        return ans;
        
    }
};