class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        queue<int> que;
        vector<int> ans;

        for(auto it : prereq){
            int l = it[0];
            int r = it[1];
            adj[r].push_back(l);
        }

        for(int i=0;i<n;i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indeg[i]==0) que.push(i);
        }

        while(!que.empty()){

            int node =  que.front();
            que.pop();
            ans.push_back(node);

            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it]==0) que.push(it);
            }

        }

        if (ans.size() != n) return {};

        return ans;
    }
};