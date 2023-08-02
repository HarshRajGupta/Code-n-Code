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

int dfs(const v<v<int>> &tree, int parent = -1, int node = 0, bool canPick = true) {
    if (dp[node][canPick] != -1) return dp[node][canPick];
    debug(parent, node, canPick)
    int ans = 0;
    foreach (child, tree[node]) {
        if (child != parent) ans += dfs(tree, node, child, true);
    }
    if (!canPick) {
        return dp[node][false] = ans;
    }
    int mx = ans;
    foreach (child, tree[node]) {
        if (child != parent) {
            int t1 = dfs(tree, node, child, false), t2 = dfs(tree, node, child, true);
            mx = max(mx, ans + t1 - t2);
        }
    }
    return dp[node][canPick] = mx;
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