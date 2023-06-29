#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    const int factorial[10] = {
        1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880
    };
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        debug(nums);
        return "";
    }
    void test() {
        getPermutation(10, 4);
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif