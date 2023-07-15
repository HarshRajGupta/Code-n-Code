#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    int minimumTotal(vector<vector<int>>& triangle, vector<vector<int>> &dp, int i, int j) {
        if (i == triangle.size()) return 0;
        if (j == triangle[i].size()) return 1e8;
        if (dp[i][j] != -1) return dp[i][j];
        int I = minimumTotal(triangle, dp, i + 1, j), I1 = minimumTotal(triangle, dp, i + 1, j + 1);
        return dp[i][j] = min(I, I1) + triangle[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), -1));
        return minimumTotal(triangle, dp, 0, 0);
    }
    void test() {
        vector<vector<int>> t = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
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