#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

const unsigned long long MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

#define Y std::cout << "YES";
#define N std::cout << "NO";

#define _for(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, n) for (auto i = a; i < n; ++i)
#define bw(i, n) for (int i = n; i >= 0; --i)

#define v std::vector
#define maxHeap std::priority_queue<int>
#define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

v<v<int>> floydWharsall(const v<v<int>> &origin) {
    v<v<int>> graph = origin;
    _for(i, sz(graph)) graph[i][i] = 0;
    _for(k, sz(graph)) _for(i, sz(graph)) if (graph[i][k] != LLONG_MAX)
        _for(j, sz(graph)) if (graph[k][j] != LLONG_MAX) graph[i][j] =
                min(graph[i][j], graph[i][k] + graph[k][j]);
    _for(i, sz(graph)) _for(j, sz(graph)) if (graph[i][j] == LLONG_MAX)
        graph[i][j] = -1;
    return graph;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    v<v<int>> graph(n, v<int>(n, LLONG_MAX));
    _for(i, m) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x - 1][y - 1] = min(w, graph[x - 1][y - 1]);
        graph[y - 1][x - 1] = min(w, graph[y - 1][x - 1]);
    }
    graph = floydWharsall(graph);
    _for(i, q) {
        int x, y;
        cin >> x >> y;
        cout << graph[x - 1][y - 1] << ln;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    solve();
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}