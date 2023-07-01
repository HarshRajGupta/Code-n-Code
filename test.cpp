#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    /* function */
    int sqr(int n) {
        return n * n;
    }
    void test() {
        int n;
        cin >> n;
        auto z = sqr(n);
        cout << z - n;
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif