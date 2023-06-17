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
    int colorfulGraph(int n, int m, vector<vector<int>> &edges, int k, vector<int> &c) {
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
    int terminalDefence(int n, int m, vector<int> &a, vector<int> &h, vector<int> &b, int k) {
        set<pair<int, int>> line;
        for (int i = 0; i < a.size(); ++i) {
            line.insert({a[i], h[i]});
        }
        for (int &i : b) line.insert({i, -1 * k});
        vector<pair<int, int>> arr(line.begin(), line.end());
        int prev = 0, fired = 0;
        for (auto &i : arr) {
            auto [x, h] = i;
            if (h < 0) {
                if (prev == 0) {
                    fired += h;
                } else {
                    prev = max(prev + h, 0);
                }
            } else {
                prev = max(prev, h + fired);
            }
        }
        debug("right")
        if (prev <= 0) return 1;
        reverse(arr.begin(), arr.end());
        prev = 0, fired = 0;
        for (auto &i : arr) {
            auto [x, h] = i;
            if (h < 0) {
                if (prev == 0) {
                    fired += h;
                } else {
                    prev = max(prev + h, 0);
                }
            } else {
                prev = max(prev, h + fired);
            }
        }
        if (prev <= 0) return 1;
        return 0;
    }
public:
    void test() {
        // vector<vector<int>> e = {{0, 1}, {0, 2}};
        // cout << colorfulGraph(4, 2, e, 2, {0, 1, 0, 2});
        vector<int> a = {2, 3, 4}, b = {1, 5, 7}, h= {10, 6, 8};
        cout << terminalDefence(3, 3, a, h, b, 5);
        // cout << scoreAndCost(a, b, 162);
    }
};

#ifdef __TEST__
__TEST__
#endif