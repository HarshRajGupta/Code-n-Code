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

const int invMod(int n, const int MOD = 1e9 + 7) {
    int ans = 1, expo = MOD - 2; n %= MOD;
    while (expo) {
        if (expo & 1) ans = (ans * 1ll * n) % MOD;
        n = (n * 1ll * n) % MOD;
        expo >>= 1;
    }
    return ans;
}


v<int> fact(1e5 + 7, 1);
int nCr(int n, int r) {
    int ans = (fact[n] * invMod((fact[n - r] * fact[r]) % MOD)) % MOD;
    return ans;
}

void solve(void) {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    set<int> arr;
    _for(i, n) {
        int x; cin >> x;
        arr.insert(x);
        mp[x]++;
    }
    v<int> a(arr.begin(), arr.end());
    debug(a)
    int ans = 0, prev = 1;
    _for(i, k) {
        prev = (prev * mp[a[i]]) % MOD;
    }
    _for(i, n - k - 1) {
        if (a[i + k] - a[i] == k) {
            ans = (ans + prev) % MOD;
        }
        prev = (prev * invMod(mp[a[i]])) % MOD;
    }
    cout << ans;
}

static bool preCompute(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.flush();
    rep(i, 2, sz(fact)) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    return 0;
}

__MAIN__