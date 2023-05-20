#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
public:
    /* function */
    void test() {
        vector<map<int, int>> mp(2);
        mp[1][0] = 4;
        mp[0][1] = 9;
        mp[0][7] = 1;
        debug(mp)
    }
};

#ifdef __TEST__
__TEST__
#endif