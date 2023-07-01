#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

struct Graph {
    vector<vector<int>> adj, edges;
    map<pair<int, int>, int> weight;
    Graph(int n) : adj(vector<vector<int>>(n)) {}
    void addEdge(int u, int v, int w = 1) {
        adj[u].push_back(v);
        edges.push_back({w, u, v});
        weight[ {u, v} ] = w;
    }
    void addUEdge(int u, int v, int w = 1) {
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    vector<int> dijkstra(int src = 0) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        vector<int> dist(adj.size(), 1e9);
        dist[src] = 0;
        while (!pq.empty()) {
            int d = pq.top().first, u = pq.top().second;
            pq.pop();
            if (d > dist[u]) continue;
            for (auto v : adj[u]) {
                if (dist[u] + weight[ {u, v} ] < dist[v]) {
                    dist[v] = dist[u] + weight[ {u, v} ];
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    vector<pair<int, vector<int>>> allPossiblePaths(int src, int dest, int target) {
        vector<pair<int, vector<int>>> paths;
        vector<int> path;
        auto d = dijkstra(dest);
        function<void(int, int, vector<pair<int, vector<int>>>&, vector<int>&, vector<int>&, int)> dfs = [&](int u, int dest, vector<pair<int, vector<int>>> &paths, vector<int> &path, vector<int> &visited, int cost) {
            cout << u << ' ' << cost << endl;
            if (cost + d[u] > target) return;
            path.push_back(u);
            visited[u] = 1;
            if (u == dest) {
                paths.push_back({cost, path});
            } else {
                for (auto v : adj[u]) {
                    if (!visited[v])
                        dfs(v, dest, paths, path, visited, cost + weight[ {u, v} ]);
                }
            }
            path.pop_back();
            visited[u] = 0;
        };
        vector<int> visited(adj.size());
        dfs(src, dest, paths, path, visited, 0);
        return paths;
    }
};

class Solution {
    vector<pair<int, int>> modifiedGraphEdges(map<pair<int, int>, int> &wt, vector<int> &path) {
        vector<pair<int, int>> edges;
        for (int i = 0; i < path.size() - 1; i++) {
            if (wt[ {path[i], path[i + 1]}]) {
                edges.push_back({path[i], path[i + 1]});
            }
        }
        return edges;
    }
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        auto g = new Graph(n);
        map<pair<int, int>, int> wt, wz;
        for (auto &e : edges) {
            if (e[2] == -1) {
                g->addUEdge(e[0], e[1], 1);
                wt[ {e[0], e[1]} ] = 1;
                wt[ {e[1], e[0]} ] = 1;
                wz[ {e[0], e[1]} ] = 1;
                wz[ {e[1], e[0]} ] = 1;
            } else {
                wz[ {e[0], e[1]} ] = e[2];
                wz[ {e[1], e[0]} ] = e[2];
                g->addUEdge(e[0], e[1], e[2]);
            }
        }
        auto d = g->dijkstra(destination), s = g->dijkstra(source);
        if (d[source] > target) return {};
        if (s[destination] == target) {
            auto ans = edges;
            for (auto &e : ans) {
                if (e[2] == -1) {
                    e[2] = max(wt[ {e[0], e[1]} ], wt[ {e[1], e[0]} ]);
                }
            }
            return ans;
        }
        for (auto &[u, v] : wt) {
            
        }

        // auto allPaths = g->allPossiblePaths(source, destination, target);
        // for (auto &[cost, path] : allPaths) {
        //     auto edges = modifiedGraphEdges(wt, path);
        //     if (!edges.size() && cost < target)
        //         return {};
        //     int currentCost = cost - edges.size();
        //     for (auto &e : edges) {
        //         // cout << e.first << " " << e.second << " " << wt[e] << endl;
        //         currentCost += wt[e];
        //         if (currentCost >= target) break;
        //     }
        //     if (currentCost >= target) continue;
        //     wt[edges[0]] += (target - currentCost);
        // }
        auto ans = edges;
        for (auto &e : ans) {
            if (e[2] == -1) {
                e[2] = max(wt[ {e[0], e[1]} ], wt[ {e[1], e[0]} ]);
            }
        }
        return ans;
    }
    void test() {
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif