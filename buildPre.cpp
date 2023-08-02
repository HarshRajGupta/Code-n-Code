#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    int f(int a, int b) {
        if (a < b) return (b, a);
        if (b != 0) return a * f(a, b - 1);
        return 0;
    }
    void test() {
        // cout << f(5, 5);
        cout << 1;
    }
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif