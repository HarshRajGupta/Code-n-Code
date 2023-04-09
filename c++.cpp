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

std::vector<int32_t> allPrimes;
std::vector<bool> sieve(int32_t n = 4000007) {
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = false, isPrime[1] = false;
    for (int32_t i = 2; (i * i) <= n; ++i) {
        if (isPrime[i]) {
            for (int j = (i * i); j <= n; j += i) isPrime[j] = false;
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (isPrime[i]) allPrimes.push_back(i);
    }
    return isPrime;
}

void solve(void) {
    sieve();
    debug(allPrimes, sz(allPrimes))
}

signed main(void) {__SOLVE__}