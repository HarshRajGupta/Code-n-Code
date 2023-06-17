#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src) {
        if (visited[src]) return;
        visited[src] = true;
        for (auto &i : adj[src]) {
            dfs(adj, visited, i);
        }
    }
    int colorfulGraph(int n, int m, vector<vector<int>> &edges, int k, vector<int> c) {
        vector<vector<int>> adj(n);
        int ans = 0;
        for (auto &i : edges) {
            if (c[i[0]] != c[i[1]]) ++ans;
            else {
                adj[i[1]].push_back(i[0]);
                adj[i[0]].push_back(i[1]);
            }
        }
        vector<bool> found(k, 0), visited(n, 0);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(adj, visited, i);
                if (!found[c[i]]) {
                    found[c[i]] = true;
                } else ++ans;
            }
        }
        return ans;
    }
public:
    void test() {
        vector<vector<int>> e = {{0,1}, {0,2}};
        cout << colorfulGraph(4, 2, e, 2, {0, 1, 0, 2});
        // vector<int> a = {3, 7, 1}, b = {2, 4, 4};
        // cout << scoreAndCost(a, b, 162);
    }
};

#ifdef __TEST__
__TEST__
#endif