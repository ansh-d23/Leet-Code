class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> &pathvis, vector<vector<int>> &adj){
        vis[node]=1;
        pathvis[node]=1;

        for(auto it : adj[node]){
            if(vis[it]==0){
                if(dfs(it,vis,pathvis,adj)==true) return true;
            }else if(pathvis[it]==1){
                return true;
            }
        }

        pathvis[node]=0;
        return false;
    }
    bool canFinish(int numcourses, vector<vector<int>>& prerequisites) {
    
        vector<vector<int>> adj(numcourses);

        for(auto it : prerequisites){
            int l = it[0];
            int r = it[1];
            adj[l].push_back(r);
        }

        vector<int> vis(numcourses,0);
        vector<int> pathvis(numcourses,0);

        for(int i=0;i<numcourses;i++){
            if(vis[i]==0){
                if(dfs(i,vis,pathvis,adj)==true) return false;
            }
        }

        return true;
    }
};