#include <bits/stdc++.h>
using namespace std;

#ifndef OFFLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse","sse2","sse3","ssse3","sse4","popcnt","abm","mmx","avx","avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

std::vector<int32_t> allPrimes;
std::vector<bool> sieve(int32_t n = 1000007) {
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = false, isPrime[1] = false;
    for (int32_t i = 2; (i * i) <= n; ++i) {
        if (isPrime[i]) {
            allPrimes.push_back(i);
            for (int j = (i * i); j <= n; j += i) isPrime[j] = false;
        }
    }
    return isPrime;
}

class Solution {
public:
    /* function */
    void test(void) {
        /* test */
        auto t = sieve();
        for (int i = 0; i < 1000007; ++i) if (t[i]) cout << i << ' ';
    }
};

#ifdef __TEST__
__TEST__
#endif