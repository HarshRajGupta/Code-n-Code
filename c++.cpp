#include <bits/stdc++.h>
using namespace std;

#ifndef OFFLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
    int MAX = -1;
    void dfs(vector<vector<int>>& graph, int node, int depth, vector<bool>& visited) {
        if (visited[node]) {
            MAX = max(MAX, depth);
            return;
        }
        visited[node] = true;
        for (auto& next : graph[node]) {
            dfs(graph, next, depth + 1, visited);
        }
        visited[node] = false;
    }
public:
    int longestCycle(vector<int>& edges) {
        vector<vector<int>> graph(edges.size());
        for (int i = 0; i < edges.size(); ++i) {
            graph[i].push_back(edges[i]);
        }
        vector<bool> visited(edges.size(), false);
        for (int i = 0; i < edges.size(); ++i) {
            dfs(graph, i, 0, visited);
        }
        return MAX;
    }
    void test(void) {
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif