class Solution {

    void bfs(int node, vector<int>& edges, vector<int>& dist,int d){
        while(node != -1 && dist[node] == -1){
            dist[node]=d;
            d++;
            node = edges[node];
        }
    }
        

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n);

        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);

        int min_dist = INT_MAX;
        int ans = -1;

        bfs(node1,edges,dist1,0);
        bfs(node2,edges,dist2,0);

        for(int i=0;i<n;i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                int maxm = max(dist1[i],dist2[i]);
                if(maxm<min_dist){
                    min_dist = maxm;
                    ans=i;
                }
            }
        }

        return ans;
    }
};
