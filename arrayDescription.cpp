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
    v<int> arr(n);
    _for(i, n) cin >> arr[i];
    v<v<int>> dp(m + 1, v<int>(n));
    int prev = 0;
    if (arr[0] == 0) {
        rep(i, 1, m + 1) {
            dp[i][0] = 1;
        }
    } else {
        dp[arr[0]][0] = 1;
    }
    rep(i, 1, n) {
        if (arr[i] != 0) {
            dp[arr[i]][i] = dp[arr[i]][i - 1];
            if (arr[i] != 1) dp[arr[i]][i] = (dp[arr[i]][i] + dp[arr[i] - 1][i - 1]) % MOD;
            if (arr[i] != m) dp[arr[i]][i] = (dp[arr[i]][i] + dp[arr[i] + 1][i - 1]) % MOD;
        } else if (prev == 0) {
            dp[1][i] = (dp[1][i] + dp[1][i - 1] + dp[2][i - 1]) % MOD;
            dp[m][i] = (dp[m][i] + dp[m - 1][i - 1] + dp[m][i - 1]) % MOD;
            rep(j, 2, m) {
                dp[j][i] = (dp[j][i] + dp[j - 1][i - 1] + dp[j][i - 1] + dp[j + 1][i - 1]) % MOD;
            }
        }
    }
    int ans = 0;
    rep(i, 1, m + 1) {
        ans = (ans + dp[i][n - 1]) % MOD;
    }
    debug(dp)
    cout << ans;
}

// void solve(void) {
//     int n, m; cin >> n >> m;
//     v<int> arr(n);
//     _for(i, n) cin >> arr[i];
//     v<v<int>> dp(n, v<int>(m + 1));
//     int prev = 0;
//     if (arr[0] == 0) {
//         rep(i, 1, m + 1) {
//             dp[0][i] = 1;
//         }
//     } else {
//         dp[0][arr[0]] = 1;
//     }
//     rep(i, 1, n) {
//         if (arr[i] != 0) {
//             dp[i][arr[i]] = dp[i - 1][arr[i]];
//             if (arr[i] != 1) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] - 1]);
//             if (arr[i] != m) dp[i][arr[i]] = (dp[i][arr[i]] + dp[i - 1][arr[i] + 1]);
//         } else if (prev == 0) {
//             dp[i][1] = (dp[i][1] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
//             dp[i][m] = (dp[i][m] + dp[i - 1][m - 1] + dp[i - 1][m]) % MOD;
//             rep(j, 2, m) {
//                 dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
//             }
//         }
//     }
//     int ans = 0;
//     rep(i, 1, m + 1) {
//         ans = (ans + dp[n - 1][i])%MOD;
//     }
//     debug(dp)
//     cout << ans;
// }

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