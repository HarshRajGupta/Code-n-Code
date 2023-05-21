#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    int factorial(int n) {
        int res = 1;
        for (int i = 2; i <= n; ++i)
            res *= i;
        return res;
    }

public:
    void test() {
        /* test */
        cout << factorial(10);
    }
};

#ifdef __TEST__
__TEST__
#endif