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

bool isPrime(int& n) {
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        return 0;
    }
    void test(void) {
        /* test */
        int n = 100000;
        while (n++) {
            if (isPrime(n)) {
                cout << n << endl;
                break;
            }
        }
    }
};

#ifdef __TEST__
__TEST__
#endif