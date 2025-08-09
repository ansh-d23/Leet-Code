class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prereq) {

        // toposort using kahn's algorithm (bfs approach)
        vector<vector<int>> adj(V);
        vector<int> indeg(V,0);

        for(auto& it : prereq){
            adj[it[0]].push_back(it[1]);
        }

        for(auto& vec : adj){
            for(int& it : vec){
                indeg[it]++;
            }
        }

        queue<int> que;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                que.push(i);
            }
        }

        vector<int> topo;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            topo.push_back(node);

            for(auto& it : adj[node]){
                indeg[it]--;
                if(indeg[it]==0) que.push(it);
            }
        }

        for(int& it : topo){
            cout<<it<<" ";
        }
        return topo.size()==V;

        
    }
};