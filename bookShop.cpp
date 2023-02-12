#ifdef ONLINE_JUDGE
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __RUN
#define __RUN solve(), std::cout << '\n'
#endif

const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

template <class T> using v = std::vector<T>;
template <class T> using xHeap = std::priority_queue<T>;
template <class T> using nHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define _for(i, n) for(int64_t i = 0; i < (int64_t)n; ++i)
#define rep(i, a, n) for(auto i = a; i < n; ++i)
#define bw(i, n) for(int64_t i = n; i >= 0; --i)

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve(void) {
    int n, m; cin >> n >> m;
    v<pair<int, int>> arr(n);
    _for(i, n) cin >> arr[i].ft;
    _for(i, n) cin >> arr[i].sd;
    v<v<int>> dp(n + 1, v<int>(m + 1, -1));
    dp[0][0] = 0;
    rep(i, 1, n + 1) {
        dp[i] = dp[i - 1];
        _for(j, m + 1 - arr[i - 1].ft) {
            if (dp[i - 1][j] == -1) continue;
            dp[i][j + arr[i - 1].ft] = max(dp[i][j + arr[i - 1].ft], dp[i - 1][j] + arr[i - 1].sd);
        }
    }
    int MAX = 0;
    debug(dp)
    _for(i, m + 1) {
        MAX = max(dp[n - 1][i], MAX);
    }
    cout << MAX;
}

signed main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    solve();
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}