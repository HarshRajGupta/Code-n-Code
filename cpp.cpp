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

vector<vector<int>> dp(2e5 + 7, vector<int>(2, -1));

int mx = 0;

int dfs(v<v<int>> &tree, int u = 0, int p = -1) {
    debug(u, p);
    maxHeap<int> heap;
    foreach (v, tree[u]) {
        if (v == p) continue;
        heap.push(dfs(tree, v, u));
    }
    if (heap.empty()) return 1;
    int t1 = heap.top();
    heap.pop();
    if (heap.empty()) {
        mx = max(mx, t1 + 1);
        return t1 + 1;
    }
    int t2 = heap.top();
    mx = max(mx, t1 + t2 + 1);
    return t1 + 1;
}


void solve(void) {
    int n;
    cin >> n;
    v<v<int>> tree(n);
    _for(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    debug(tree)
    cout << dfs(tree);
}

/**
 * @ScratchPad
 */

__SOLVE__