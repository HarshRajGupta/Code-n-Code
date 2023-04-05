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

int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int modInverse(int b, int m = MOD) {
    int x, y;
    int g = gcdExtended(b, m, &x, &y);
    if (g != 1)
        return -1;
    return (x % m + m) % m;
}

int  modDivide(int a, int b, int m = MOD) {
    a = a % m;
    int inv = modInverse(b, m);
    if (inv == -1)
        return -1;
    return (inv * a) % m;
}

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

int t(int a, int b) {
    debug(a, b)
    int inv_b = 1, p = MOD - 2;
    while (p) {
        if (p % 2) inv_b = (long long) inv_b * b % MOD;
        b = (long long) b * b % MOD;
        p /= 2;
    }
    return (long long) a * inv_b % MOD;
}

void solve(void) {
    int i = 143232634734, j = 532634674575485;
    cout << modDivide(j, i) % MOD << '\n';
    cout << modDivide(j % MOD, i % MOD) << '\n';
    cout << t(j % MOD, i % MOD) % MOD << '\n';
    cout << (j * invMod(i)) % MOD << '\n';
    cout << (j / i);
}

signed main(void) {__SOLVE__}