#include <bits/stdc++.h>
// using namespace std;

const long long MOD = 1e9 + 7;
#define pr ((rand() * (rand() % 7 + 1) * (rand() % 7 + 1) * 1ll % MOD) / (rand() % 7 + 1))
#define r (pr * (rand() & 1 ? -1ll : 1ll))

class Solution {
    void generateTestCase(void) {
        /* generate test case */
        std::cout << pr;
    }
public:
    void test(void) {
        int t = rand() % 29; std::cout << t << '\n';
        while (t--) generateTestCase(), std::cout << '\n';
    }
};

#ifdef __TEST__
__TEST__
#endif