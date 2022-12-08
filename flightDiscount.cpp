// #pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")

// #include <bits/stdc++.h>
// using namespace std;

// #ifndef debug
// #define debug(...)
// #endif

// const unsigned long long MOD = 1e9 + 7;
// const char ln = '\n';

// #define int long long
// #define ll long double

// #define Y std::cout << "YES";
// #define N std::cout << "NO";

// #define _for(i, n) for (int i = 0; i < n; ++i)
// #define rep(i, a, n) for (auto i = a; i < n; ++i)
// #define bw(i, n) for (int i = n; i >= 0; --i)

// #define v std::vector
// #define maxHeap std::priority_queue<int>
// #define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

// #define ft first
// #define sd second
// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()

// int maxPrice(const v<v<pair<int, int>>> &graph, bitset<100001> &visiting,
//              v<v<int>> &dp, const bool halved = false, int pos = 0) {
//     if (pos == sz(graph) - 1)
//         return 0;
//     if (visiting[pos])
//         return LLONG_MAX;
//     if (dp[pos][halved] != -1)
//         return dp[pos][halved];
//     visiting[pos] = 1;
//     if (halved) {
//         int MIN = LLONG_MAX;
//         for (auto i : graph[pos]) {
//             int temp = maxPrice(graph, visiting, dp, true, i.sd);
//             if (temp != LLONG_MAX)
//                 MIN = min(temp + i.ft, MIN);
//         }
//         visiting[pos] = 0;
//         return dp[pos][1] = MIN;
//     }
//     int MIN = LLONG_MAX;
//     for (auto i : graph[pos]) {
//         int temp = maxPrice(graph, visiting, dp, false, i.sd);
//         if (temp != LLONG_MAX)
//             MIN = min(temp + i.ft, MIN);
//     }
//     for (auto i : graph[pos]) {
//         int temp = maxPrice(graph, visiting, dp, true, i.sd);
//         if (temp != LLONG_MAX)
//             MIN = min(temp + (i.ft / 2), MIN);
//     }
//     visiting[pos] = 0;
//     return dp[pos][0] = MIN;
// }

// int minPrice(const v<v<pair<int, int>>> &graph, bitset<100001> &visited,
//              v<v<int>> &dp, const int halved = 0, int pos = 0) {
//     if (pos == sz(graph) - 1)
//         return 0;
//     if (visited[pos])
//         return LLONG_MAX;
//     if (dp[halved][pos] != -1)
//         return dp[halved][pos];
//     int ans = LLONG_MAX;
//     visited[pos] = 1;
//     if (halved) {
//         _for(i, sz(graph[pos])) {
//             int curr = minPrice(graph, visited, dp, 1, graph[pos][i].sd);
//             if (curr != LLONG_MAX)
//                 ans = min(ans, curr + graph[pos][i].ft);
//         }
//         visited[pos] = 0;
//         return dp[1][pos] = ans;
//     }
//     _for(i, sz(graph[pos])) {
//         int curr = minPrice(graph, visited, dp, 0, graph[pos][i].sd);
//         if (curr != LLONG_MAX)
//             ans = min(ans, curr + graph[pos][i].ft);
//     }
//     _for(i, sz(graph[pos])) {
//         int curr = minPrice(graph, visited, dp, 1, graph[pos][i].sd);
//         if (curr != LLONG_MAX)
//             ans = min(ans, curr + (graph[pos][i].ft / 2));
//     }
//     visited[pos] = 0;
//     return dp[0][pos] = ans;
// }

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     v<v<pair<int, int>>> graph(n);
//     _for(i, m) {
//         int x, y = 0, w = 0;
//         cin >> x >> y >> w;
//         graph[x - 1].push_back({w, y - 1});
//     }
//     v<v<int>> dp(2, v<int>(n, -1));
//     bitset<100001> visited;
//     v<v<int>> dp2(n + 1, { -1, -1});
//     cout <<  maxPrice(graph, visited, dp2)  << " " << minPrice(graph,
//     visited, dp);
//     // _for(i, n) {
//     //     debug(i, dp[i])
//     // }
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// #ifdef __TAG1
//     __TAG1
// #endif
//     solve();
// #ifdef __TAG2
//     __TAG2
// #endif
//     return 0;
// }

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

int minimumCostSimplePath(int u, int destination, bool visited[],
                          const v<v<int>> &graph) {
    if (u == destination)
        return 0;
    visited[u] = 1;
    int ans = LLONG_MAX;
    for (int i : graph[u]) {
        if (!visited[i]) {
            int curr = minimumCostSimplePath(i, destination, visited, graph);
            if (curr < LLONG_MAX) {
                ans = min(ans, graph[u][i] + curr);
            }
        }
    }
    visited[u] = 0;
    return ans;
}

int minPrice(const v<v<pair<int, int>>> &graph, bitset<100001> &visited,
             v<v<int>> &dp, const int halved = 0, int pos = 0) {
    if (pos == sz(graph) - 1)
        return 0;
    if (dp[halved][pos] != -1)
        return dp[halved][pos];
    if (visited[pos])
        return LLONG_MAX;
    visited[pos] = 1;
    int ans = LLONG_MAX;
    if (halved) {
        _for(i, sz(graph[pos])) {
            int curr = minPrice(graph, visited, dp, 1, graph[pos][i].sd);
            if (curr != LLONG_MAX)
                ans = min(ans, curr + graph[pos][i].ft);
        }
        visited[pos] = 0;
        return dp[1][pos] = ans;
    }
    _for(i, sz(graph[pos])) {
        int curr = minPrice(graph, visited, dp, 0, graph[pos][i].sd);
        if (curr != LLONG_MAX)
            ans = min(ans, curr + graph[pos][i].ft);
    }
    _for(i, sz(graph[pos])) {
        int curr = minPrice(graph, visited, dp, 1, graph[pos][i].sd);
        if (curr != LLONG_MAX)
            ans = min(ans, curr + (graph[pos][i].ft / 2));
    }
    visited[pos] = 0;
    return dp[0][pos] = ans;
}

int maxPrice(const v<v<pair<int, int>>> &graph, bitset<100001> &visiting,
             v<v<int>> &dp, const bool halved = false, int pos = 0) {
    if (pos == sz(graph) - 1)
        return 0;
    if (visiting[pos])
        return LLONG_MAX;
    if (dp[pos][halved] != -1)
        return dp[pos][halved];
    visiting[pos] = 1;
    if (halved) {
        int MIN = LLONG_MAX;
        for (auto i : graph[pos]) {
            int temp = maxPrice(graph, visiting, dp, true, i.sd);
            if (temp != LLONG_MAX)
                MIN = min(temp + i.ft, MIN);
        }
        visiting[pos] = 0;
        return dp[pos][1] = MIN;
    }
    int MIN = LLONG_MAX;
    for (auto i : graph[pos]) {
        int temp = maxPrice(graph, visiting, dp, false, i.sd);
        if (temp != LLONG_MAX)
            MIN = min(temp + i.ft, MIN);
    }
    for (auto i : graph[pos]) {
        int temp = maxPrice(graph, visiting, dp, true, i.sd);
        if (temp != LLONG_MAX)
            MIN = min(temp + (i.ft / 2), MIN);
    }
    visiting[pos] = 0;
    return dp[pos][0] = MIN;
}

void solve() {
    int n, m;
    cin >> n >> m;
    v<v<pair<int, int>>> graph(n);
    _for(i, m) {
        int x, y = 0, w = 0;
        cin >> x >> y >> w;
        graph[x - 1].push_back({w, y - 1});
    }
    // _for(i, n) {
    //     sort(all(graph[i]));
    // }
    bitset<100001> visiting, visiting2;
    v<v<int>> dp(n + 1, { -1, -1}), dp2(2, v<int>(n, -1));
    // cout << maxPrice(graph, visiting, dp) << ln;
    // cout << minPrice(graph, visiting2, dp2);
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