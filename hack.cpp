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
#define __MAIN__ ios_base::sync_with_stdio(0);cin.tie(0);signed t;cin>>t;while(t--)solve(),cout<<'\n';return 0;
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define _for(i, n) for (int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for (int32_t i = a; i < (int32_t)n; ++i)
#define foreach(i, x) for (auto &i : x)
#define bw(i, n) for (int32_t i = n; i >= 0; --i)

template<class T>using v = std::vector<T>;
template<class T>using maxHeap = std::priority_queue<T>;
template<class T>using minHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

vector<int> fact(100);
void factorial() {
    fact[0] = 1;
    rep(i, 1, 100) fact[i] = (i * fact[i - 1]) % MOD;
}

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
    int n, cnt = 0; cin >> n;
    while (n) {
        if (n & 1) ++cnt;
        n /= 2;
    }
    if (cnt < 3) {
        cout << 0;
        return;
    }
    cout << (modDivide(fact[cnt], (fact[3] * fact[cnt - 3])) * 6ll) % MOD;
}

signed main(void) {
    factorial();
    __MAIN__
}