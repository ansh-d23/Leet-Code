class Solution {
public:
    int dfs(int par,int node,vector<vector<int>>& adj,int &count){
        int size =1;
        unordered_set<int> uni_size;
        for(auto child : adj[node]){
            if(child==par) continue;
            int curr_size = dfs(node,child,adj,count);
            size+=curr_size;
            uni_size.insert(curr_size);
        }

        if(uni_size.size()<=1) count++;
        return size;
    }
    int countGoodNodes(vector<vector<int>>& edges) {

        int n = edges.size();
        vector<vector<int>> adj(n+5);

        for(auto it :  edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int good_count=0;

        dfs(-1,0,adj,good_count);
        return good_count;
        
    }
};