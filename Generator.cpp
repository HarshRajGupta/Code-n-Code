#include <bits/stdc++.h>

const long long MOD = 1e9 + 7;
#define pr ((rand() * (rand() % 7 + 1) * (rand() % 7 + 1) * 1ll % MOD) / (rand() % 7 + 1))
#define r ((pr * (rand() & 1 ? -1ll : 1ll)))

class Solution {
    void generateArray(int n = rand()) {
        printf("%d\n", n); while (n--) printf("%d ", r); printf("\n");
    }
    void generateString(int n = rand()) {
        std::cout << n << '\n'; while (n--) std::cout << (char)('a' + rand() % 26); std::cout << '\n';
    }
    void generateTestCase(void) {
        /* generate test case */
    }
public:
    void test(void) {
        int t = rand() % 7; std::cout << t << '\n';
        while (t--) generateTestCase();
    }
};

#ifdef __TEST__
__TEST__
#endif