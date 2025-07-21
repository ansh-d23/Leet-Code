#define ll long long
const ll nax = 1e15;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto e : edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            if(online[u] && online[v] && w<=k){
                adj[u].emplace_back(v,w);
            }
        }

        int low=0;
        int high=1e9;
        int ans=-1;

        while(low<=high){
            int mid = low + (high-low)/2;
            vector<ll> dist(n,nax);
            dist[0]=0;

            set<pair<ll,int>> st;
            st.insert({0,0});
            while(!st.empty()){
                auto p = *st.begin();
                st.erase(st.begin());
                for(auto nbs : adj[p.second]){
                    if(nbs.second>=mid && dist[nbs.first]>p.first+nbs.second){
                        dist[nbs.first]=p.first+nbs.second;
                        st.insert({dist[nbs.first],nbs.first});
                    }
                }
            }

            if(dist[n-1]<=k){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return ans;
    }
};