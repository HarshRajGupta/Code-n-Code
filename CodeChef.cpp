#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#ifndef __MAIN__
#define __MAIN__ signed main() {preCompute(); signed t; cin >> t; while (t--)solve(), cout << '\n'; return 0;}
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define _for(i, n) for (int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for (int32_t i = a; i < (int32_t)n; ++i)
#define foreach(i, x) for (auto &i : x)
#define bw(i, n) for (int32_t i = n; i >= 0; --i)

template<class T>using v = vector<T>;
template<class T>using maxHeap = priority_queue<T>;
template<class T>using minHeap = priority_queue<T, vector<T>, greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int power(int n, int expo, int MOD = 1e9 + 7) {
    int ans = 1; n %= MOD;
    while (expo) {
        if (expo & 1) ans = (ans * 1ll * n) % MOD;
        n = (n * 1ll * n) % MOD;
        expo >>= 1;
    }
    return ans;
}

map<int32_t, map<int32_t, int32_t>> dp;
int nCr(int n, int r) {
    if (dp[n][r]) return dp[n][r];
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return dp[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % MOD;
}

void solve(void) {
    int n; cin >> n;
    v<int> arr(n);
    foreach(i, arr) cin >> i;
    sort(all(arr));
    v<int> a(n);
    foreach (i, arr) {
        if (i > n) continue;
        ++a[i - 1];
    }
    int ans = 0, count = 0;
    _for(i, n) {
        int temp = power(2, n - count - a[i]);
        if (count >= i) {
            temp = (temp * nCr(count, i)) % MOD;
            temp = (temp * (power(2, a[i]) - 1 + MOD)) % MOD;
            ans = (ans + temp) % MOD;
        } else {
            if (count + a[i] > i) {
                temp = (temp * (power(2, count + a[i] - i) - 1)) % MOD;
                ans = (ans + temp) % MOD;
            }
        }
        count += a[i];
    }
    cout << ans;
}

static bool preCompute(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.flush(); return 0;
}

__MAIN__