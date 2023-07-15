#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle, int i = 0, int j = 0) {
        if (i == triangle.size()) return 0;
        if (j == triangle[i].size()) return 1e8;
        int I = minimumTotal(triangle, i + 1, j), I1 = minimumTotal(triangle, i + 1, j + 1);
        return min(I, I1) + triangle[i][j];
    }
    void test() {
        vector<vector<int>> t = {{2},{3,4},{6,5,7},{4,1,8,3}};
        cout << minimumTotal(t);
    }
    Solution() {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif