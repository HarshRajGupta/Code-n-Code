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

void vertexTraversal(const v<v<pair<int, int>>> &graph, v<int> &dist,
                     set<pair<int, int>> &q, bitset<100001> &visited) {
    int pos = (*q.begin()).sd;
    q.erase(q.begin());
    if (visited[pos])
        return;
    visited[pos] = 1;
    _for(i, sz(graph[pos])) {
        if (dist[graph[pos][i].ft] > graph[pos][i].sd + dist[pos]) {
            q.erase({dist[graph[pos][i].ft], graph[pos][i].ft});
            dist[graph[pos][i].ft] = graph[pos][i].sd + dist[pos];
            q.insert({dist[graph[pos][i].ft], graph[pos][i].ft});
        }
    }
}

v<int> dijkstra(const v<v<pair<int, int>>> &graph, const int src = 0) {
    v<int> dist(sz(graph), LLONG_MAX);
    dist[src] = 0;
    bitset<100001> visited;
    set<pair<int, int>> Q;
    Q.insert({0, src});
    while (!Q.empty())
        vertexTraversal(graph, dist, Q, visited);
    return dist;
}

void solve() {
    int n, m;
    cin >> n >> m;
    v<v<pair<int, int>>> graph(n);
    _for(i, m) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x - 1].push_back({y - 1, w});
    };
    auto dist = dijkstra(graph);
    for (auto i : dist) cout << i << " ";
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