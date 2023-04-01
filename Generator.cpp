#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)
#define r ((rand() * (rand() % 107 + 1) * (rand() & 1 ? -1ll : 1ll)) % MOD)

class Solution {
    void generateTestCase(void) {
        /* generate test case */
        int pr = rand() * rand() % 100;
        cout << pr << ' ';
    }
public:
    void test(void) {
        int n = 20; cout << n << '\n';
        rep(i, 0, n) {
            generateTestCase();
        }
    }
};

#ifdef __TEST__
__TEST__
#endif