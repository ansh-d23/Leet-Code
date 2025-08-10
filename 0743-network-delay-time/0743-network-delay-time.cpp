class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        k--;
        vector<vector<pair<int,int>>> adj(n);
        vector<int> mint(n,1e9);

        for(auto& it : times){
            adj[it[0]-1].push_back({it[2],it[1]-1});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //min heap

        pq.push({0,k});
        mint[k]=0;

        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();

            for(auto [wt, v] : adj[node]){
                if(time+wt < mint[v]){
                    mint[v] = time+wt;
                    pq.push({mint[v],v});
                }
            }
        }

        int maxm=0;
        for(int i=0;i<n;i++){
            if(mint[i]==1e9) return -1;
            maxm = max(maxm, mint[i]);
        }

        return maxm;

    }
};