#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    string getPermutation(int n, int k) {

    }
    void test() {
        vector<int> factorial(10);
        factorial[0] = 1;
        for (int i = 1; i < 10; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        debug(factorial);
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif