class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, INT_MAX);

        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto it : adj[node]){
                int val = it.second;
                int nxt = it.first;
                if(wt + val < dist[nxt]){
                    dist[nxt]=wt+val;
                    pq.push({dist[nxt],nxt});
                }
            }
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }

        return ans;
        
    }
};