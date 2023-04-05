#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#ifndef __SOLVE__
#define __SOLVE__ ios_base::sync_with_stdio(0);cin.tie(NULL);solve();return 0;
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;

#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)
#define bw(i, n) for(int32_t i = n; i >= 0; --i)

template <class T> using v = std::vector<T>;
template <class T> using maxHeap = std::priority_queue<T>;
template <class T> using minHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

vector<int> fact(100);
void factorial() {
    fact[0] = 1;
    rep(i, 1, 100) fact[i] = (i * fact[i - 1]) % MOD;
}

const int invMod(int n) {
    int ans = 1, expo = MOD - 2; n %= MOD;
    while (expo) {
        if (expo & 1) ans = (ans * 1ll * n) % MOD;
        n = (n * 1ll * n) % MOD;
        expo >>= 1;
    }
    return ans;
}

void solve(void) {
    factorial();
    rep(i, 3, 100) {
        int ans = ((fact[i] * invMod((fact[i - 3] * fact[3]))) * 6) % MOD;
        cout << ans << ", ";
    }
}

signed main(void) {__SOLVE__}