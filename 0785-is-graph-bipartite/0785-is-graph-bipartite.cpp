class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> que;
        vector<int> color(n, -1);

        for (int start = 0; start < n; start++) {
            if (color[start] != -1) continue; 

            color[start] = 0;
            que.push(start);

            while (!que.empty()) {
                int u = que.front();
                que.pop();

                for (int v : graph[u]) {
                    if (color[v] != -1 && color[u] == color[v]) {
                        return false;
                    }
                    if (color[v] == -1) { 
                        color[v] = 1 - color[u];
                        que.push(v);
                    }
                }
            }
        }

        return true;
    }
};
