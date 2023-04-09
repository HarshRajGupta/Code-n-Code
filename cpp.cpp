#include <bits/stdc++.h>
using namespace std;

#ifndef OFFLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse","sse2","sse3","ssse3","sse4","popcnt","abm","mmx","avx","avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, INT_MAX));
        dp[n - 1][m - 1] = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i == n - 1 && j == m - 1) {
                    continue;
                }
                int x = grid[i][j];
                for (int k = j + 1; k <= j + x && k < m; ++k) {
                    dp[i][j] = min(dp[i][j], 1ll + dp[i][k]);
                }
                for (int k = i + 1; k <= i + x && k < n; ++k) {
                    dp[i][j] = min(dp[i][j], 1ll + dp[k][j]);
                }
            }
        }
        debug(dp)
        return (dp[0][0] == INT_MAX ? -1 : dp[0][0]);
    }
    void test(void) {
        vector<vector<int>> t = {{3, 4, 2, 1}, {4, 2, 3, 1}, {2, 1, 0, 0}, {2, 4, 0, 0}};
        cout << minimumVisitedCells(t);
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif