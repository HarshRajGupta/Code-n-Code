#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3", "fast-math", "unroll-loops", "no-stack-protector", \
                         "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "sse4", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __SOLVE__
#define __SOLVE__   \
    signed main() { \
        solve();    \
        return 0;   \
    }
#endif

// #define int long long
const uint64_t MOD = 1e9 + 7;

#define _for(i, n) for (int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for (int32_t i = a; i < (int32_t)n; ++i)
#define foreach(i, x) for (auto &i : x)

template <class T>
using v = vector<T>;
template <class T>
using maxHeap = priority_queue<T>;
template <class T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve(void) {
    string s;
    cin >> s;
    v<v<int>> graph(10);
    _for(i, sz(s)) { graph[s[i] - '0'].push_back(i); }
    debug(graph) minHeap<pair<int, int>> q;
    v<int> dist(sz(s), 1e6);
    dist[0] = 0;
    q.push({0, s[0] - '0'});
    while (!q.empty()) {
        auto [cost, cur] = q.top();
        q.pop();
        foreach (i, graph[cur]) {
            debug(i, cur, cost, dist[i])
            if (dist[i] > cost + 1) { dist[i] = cost + 1; }
            if (i == sz(s) - 1) break;
            if (i > 0 && (dist[i - 1] > dist[i] + 1)) {
                dist[i - 1] = dist[i] + 1;
                q.push({dist[i - 1], s[i - 1] - '0'});
            }
            if ((dist[i + 1] > dist[i] + 1)) {
                dist[i + 1] = dist[i] + 1;
                if (i + 1 == sz(s) - 1) break;
                q.push({dist[i + 1], s[i + 1] - '0'});
            }
        }
    }
    debug(dist) cout << dist[sz(s) - 1] << endl;
}

/**
 * @ScratchPad
 */

__SOLVE__