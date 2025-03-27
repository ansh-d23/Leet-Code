#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& it : roads) {
            int u = it[0], v = it[1], t = it[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        long long MOD = 1e9 + 7;

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue;

            for (auto& [neighbor, travel_time] : adj[node]) {

                if (time + travel_time < dist[neighbor]) {

                    dist[neighbor] = time + travel_time;
                    ways[neighbor] = ways[node]; 
                    pq.push({dist[neighbor], neighbor});

                } else if (time + travel_time == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1]; 
    }
};
