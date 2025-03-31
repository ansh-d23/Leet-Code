class Disjoint{
    vector<int> parent;
    vector<int> rank;
    public:

    Disjoint(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int find(int u){
        if(parent[u]==u) return u;
        return parent[u] = find(parent[u]);
    }

    void unionbyrank(int u,int v){
        int up_u = find(u);
        int up_v = find(v);

         if (up_u == up_v) return;

        if(rank[up_u]<rank[up_v]){
            parent[up_u]=up_v;
        }else if(rank[up_v]<rank[up_u]){
            parent[up_v]=up_u;
        }else{
            parent[up_u]=up_v;
            rank[up_v]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1) return -1;

        int count=0;
        Disjoint ds(n);

        for(auto it : connections){
            int u=it[0];
            int v=it[1];

            int up_u = ds.find(u);
            int up_v = ds.find(v);

            if(up_u==up_v){
                count++;
            }else{
                ds.unionbyrank(u,v);
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.find(i) == i) {
                components++;
            }
        }

        if(count>= components-1){
            return components-1;
        }else{
            return -1;
        }
    }
};