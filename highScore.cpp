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

// bool detectWeightCycle(const v<v<pair<int, int>>> &origin, int src = 0) {
//     auto graph = origin;
//     _for(i, sz(graph)) {
//         _for(j, sz(graph[i])) {
//             if (graph[i][j].sd == 0) continue;
//             if (graph[i][j].sd < 0)
//                 graph[i][j].sd = -1000;
//             else
//                 graph[i][j].sd = 1000;
//         }
//     }
//     // debug(graph)
//     v<int> dist(sz(graph), LLONG_MAX);
//     dist[src] = -1;
//     bool loopMore = true;
//     for (int k = 0; (k < max(sz(graph), 1000ll)) && loopMore; ++k) {
//         loopMore = false;
//         _for(i, sz(graph)) {
//             if (dist[i] != LLONG_MAX) {
//                 _for(j, sz(graph[i])) {
//                     if (dist[graph[i][j].ft] > dist[i] + graph[i][j].sd) {
//                         dist[graph[i][j].ft] = dist[i] + graph[i][j].sd;
//                         loopMore = true;
//                     }
//                 }
//             }
//         }
//     }
//     debug(dist)
//     int pre = dist[sz(graph) - 1];
//     for (int k = 0; (k < max(sz(graph), 1000ll)); ++k) {
//         _for(i, sz(graph)) {
//             if (dist[i] != LLONG_MAX) {
//                 _for(j, sz(graph[i])) {
//                     if (dist[graph[i][j].ft] > (dist[i] + graph[i][j].sd)) {
//                         dist[graph[i][j].ft] = (dist[i] + graph[i][j].sd);
//                     }
//                 }
//             }
//         }
//         // debug(dist)
//     }
//     // debug(dist)
//     return !(pre == dist[sz(graph) - 1]);
// }

int bellmanFord(const v<v<pair<int, int>>> &graph, const v<bool> &endEdge,
                int src = 0) {
    v<int> dist(sz(graph), LLONG_MAX);
    dist[src] = 0;
    bool loopMore = true;
    for (int k = 0; (k < sz(graph)) && loopMore; ++k) {
        loopMore = false;
        _for(i, sz(graph)) {
        
            if (dist[i] != LLONG_MAX) {
                _for(j, sz(graph[i])) {
                    if (dist[graph[i][j].ft] > dist[i] + graph[i][j].sd) {
                        dist[graph[i][j].ft] = dist[i] + graph[i][j].sd;
                        loopMore = true;
                    }
                }
            }
        }
    }
    for (int k = 0; (k < sz(graph)) && loopMore; ++k) {
        loopMore = false;
        _for(i, sz(graph)) {
            if (dist[i] != LLONG_MAX) {
                _for(j, sz(graph[i])) {
                    if (dist[graph[i][j].ft] > dist[i] + graph[i][j].sd) {
                        if (endEdge[graph[i][j].ft])
                            return -1;
                        dist[graph[i][j].ft] = dist[i] + graph[i][j].sd;
                        loopMore = true;
                    }
                }
            }
        }
    }
    return dist[sz(graph) - 1] * -1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    v<v<pair<int, int>>> graph(n);
    v<bool> endEdge(n, false);
    endEdge[n - 1] = true;
    _for(i, m) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x - 1].push_back({y - 1, -1 * w});
        if (endEdge[y - 1])
            endEdge[x - 1] = true;
    }
    _for(i, n) {
        if (!endEdge[i])
            _for(j, sz(graph[i])) {
            if (endEdge[graph[i][j].ft])
                endEdge[i] = true;
        }
    }
    cout << bellmanFord(graph, endEdge);
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