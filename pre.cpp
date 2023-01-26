#ifndef __FAST_IO
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...) ;
#endif

#ifndef __RUN
#define __RUN solve(), std::cout << '\n'
#endif

const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

#define Y std::cout << "YES";
#define N std::cout << "NO";

#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for(auto i = a; i < n; ++i)
#define bw(i, n) for(int32_t i = (int32_t)n; i >= 0; --i)

#define v std::vector
#define maxHeap std::priority_queue<int>
#define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()


long long powmod(long long base, long long exponent) {
    long long res = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return res;
}
long long factmod(long long n) {
    long long res = 1;
    for (long long i = 2; i <= n; i++)
        res = (res * i) % MOD;
    return res;
}
long long invmod(long long a) {
    return powmod(a, MOD - 2);
}

int power(int n) {
    int ans = 1, x = 2;
    while (n) {
        if (n & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return ans;
}

int nCn(int n) {
    return (((factmod(n) * invmod(factmod(n / 2))) % MOD) * invmod(factmod(n - (n / 2)))) % MOD;
}

void solve() {
    // int n; cin >> n;
    // string s1, s2; cin >> s1 >> s2;
    // int diff = 0;
    // _for(i, n) {
    //     if (s1[i] != s2[i]) ++diff;
    // }
    // if (diff & 1) {
    //     cout << 0;
    // } else {
    //     int ans = nCn(diff);
    //     ans = (ans * power(n - diff)) % MOD;
    //     cout << ans;
    // }
    cout << nCn(100002);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    uint32_t tCs = 1u;
    cin >> tCs;
    for (uint32_t tC = 0u; tC++ < tCs; __RUN);
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}