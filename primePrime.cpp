#ifndef __FAST_IO
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

std::vector<int32_t> allPrimes, primePrime(1e6 + 7);
std::vector<bool> sieve(int n = 1000007) {
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = false, isPrime[1] = false;
    for (int i = 2; (i * i) <= n; ++i)
        if (isPrime[i])
            for (int j = (i * i); j <= n; j += i)
                isPrime[j] = false;
    for (int i = 2; i <= n; ++i)
        if (isPrime[i])
            allPrimes.push_back(i);
    int cnt = 0, pp = 0;
    for (int i = 0; i <= n; ++i) {
        if (isPrime[i]) ++cnt;
        if (isPrime[cnt]) ++pp;
        primePrime[i] = pp;
    }
    return isPrime;
}

void solve() {
    int l, r; cin >> l >> r;
    cout << primePrime[r] - primePrime[l - 1];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    sieve();
#ifdef __TAG1
    __TAG1
#endif
    uint32_t tCs; cin >> tCs;
    for (uint32_t tC = 0; tC++ < tCs; __RUN);
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}