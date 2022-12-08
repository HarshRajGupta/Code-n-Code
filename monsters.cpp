// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

// #include <bits/stdc++.h>
// using namespace std;

// #ifndef debug
// #define debug(...)
// #endif

// #ifndef __VALID_CASE
// #define __VALID_CASE(...) 1
// #endif

// const unsigned long long MOD = 1e9 + 7;
// const char ln = '\n';

// // #define int long long
// #define ll long double

// #define check(x) std::cout << ((x) ? "YES\n" : "NO\n")
// #define print(x) std::cout << x << '\n'

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

// void pathTraversal(const v<string> &graph, int x, int y,
//                    queue<pair<int, int>> &arr, v<v<int>> &res) {
//     arr.pop();
//     if (x >= sz(graph) || y >= sz(graph[0]) || graph[x][y] == '#' ||
//             graph[x][y] == 'A')
//         return;
//     if (x < sz(graph) - 1 && res[x + 1][y] > res[x][y] + 1 &&
//             graph[x + 1][y] != '#') {
//         res[x + 1][y] = res[x][y] + 1;
//         arr.push(make_pair(x + 1, y));
//     }
//     if (y < sz(graph[0]) - 1 && res[x][y + 1] > res[x][y] + 1 &&
//             graph[x][y + 1] != '#') {
//         res[x][y + 1] = res[x][y] + 1;
//         arr.push(make_pair(x, y + 1));
//     }
//     if (x > 0 && res[x - 1][y] > res[x][y] + 1 && graph[x - 1][y] != '#') {
//         res[x - 1][y] = res[x][y] + 1;
//         arr.push(make_pair(x - 1, y));
//     }
//     if (y > 0 && res[x][y - 1] > res[x][y] + 1 && graph[x][y - 1] != '#') {
//         res[x][y - 1] = res[x][y] + 1;
//         arr.push(make_pair(x, y - 1));
//     }
//     debug(arr) while (!arr.empty()) {
//         pathTraversal(graph, arr.front().ft, arr.front().sd, arr, res);
//     }
// }

// int n, m;
// bool ans(const v<string> &arr, const v<v<int>> &graph, v<v<bool>> &visited,
//          string &res, const int &x, const int &y, const int &pos) {
//     if (((x == 0) || (y == 0) || (x >= (n - 1)) || (y >= m - 1)) &&
//             arr[x][y] != '#' && graph[x][y] > pos) {
//         debug(x, y, pos, graph[x][y], '-') return true;
//     }
//     if ((x == 0) || (y == 0) || (x >= n - 1) || (y >= m - 1) || visited[x][y] ||
//             arr[x][y] == '#' || graph[x][y] <= pos) {
//         debug(x, y, pos, graph[x][y], '*') return false;
//     }
//     visited[x][y] = true;
//     string L = "", R = "", U = "", D = "", result = "0";
//     if (ans(arr, graph, visited, D, x + 1, y, pos + 1))
//         result = D + 'D';
//     if (ans(arr, graph, visited, R, x, y + 1, pos + 1))
//         if (result == "0" || sz(result) > sz(R))
//             result = R + 'R';
//     if (ans(arr, graph, visited, L, x, y - 1, pos + 1))
//         if (result == "0" || sz(result) > sz(L))
//             result = L + 'L';
//     if (ans(arr, graph, visited, U, x - 1, y, pos + 1))
//         if (result == "0" || sz(result) > sz(U))
//             result = U + 'U';
//     // debug(x, y, pos, graph[x][y], result)
//     if (result == "0") {
//         return false;
//     }
//     res = result;
//     return true;
// }

// void solve() {
//     // int n, m;
//     cin >> n >> m;
//     v<string> arr(2 * n);
//     _for(i, n) cin >> arr[i];
//     queue<pair<int, int>> tra;
//     v<v<int>> graph(2 * n, v<int>(2 * m, INT_MAX));
//     int x = n, y = m;
//     _for(i, n) {
//         _for(j, m) {
//             if (arr[i][j] == 'M') {
//                 tra.push({i, j});
//                 graph[i][j] = 0;
//             } else if (arr[i][j] == 'A') {
//                 x = i;
//                 y = j;
//             }
//         }
//     }
//     string t;
//     if (!tra.empty())
//         pathTraversal(arr, tra.front().ft, tra.front().sd, tra, graph);
//     // debug(graph)
//     v<v<bool>> visit(n, v<bool>(m, false));
//     check(ans(arr, graph, visit, t, x, y, 0));
//     print(sz(t));
//     reverse(all(t));
//     print(t);
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

#include <queue>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __VALID_CASE
#define __VALID_CASE(...) 1
#endif

const unsigned long long MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

#define check(x) std::cout << ((x) ? "YES\n" : "NO\n")
#define print(x) std::cout << x << '\n'

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

v<int> dx = {0, 0, 1, -1};
v<int> dy = {1, -1, 0, 0};

void monsterPath(const v<string> &arr, v<v<int>> &graph, queue<v<int>> &monsterRecords) {
    auto curr = monsterRecords.front();
    monsterRecords.pop();
    int i = curr[0], j = curr[1], pos = curr[2];
    if (i < 0 || j < 0 || i >= sz(arr) || j >= sz(arr[0]) || arr[i][j] == '#' || graph[i][j] != -1)
        return;
    graph[i][j] = pos;
    _for(a, 4) {
        monsterRecords.push({i + dx[a], j + dy[a], pos + 1});
    }
}

bool ans(const v<v<int>> &graph, queue<v<int>> &pathRecord, string &ans) {
    auto curr = pathRecord.front();
    pathRecord.pop();
    int i = curr[0], j = curr[1], w = curr[0];
    if (i < 0 || j < 0 || i >= sz(graph) || j >= sz(graph[0]) || graph[i][j] == -1)
        return false;
}

void solve() {
    int n, m; cin >> n >> m;
    v<string> arr(n);
    _for(i, n) {
        cin >> arr[i];
    }
    v<v<int>> graph(n, v<int>(m, -1));
    queue<v<int>> q;
    _for(i, n) {
        _for(j, m) {
            if (arr[i][j] == 'M') {
                q.push({i, j, 0});
            }
        }
    }
    while (!q.empty()) {
        monsterPath(arr, graph, q);
    }
    debug(graph)
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