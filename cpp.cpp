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
        vector<long long> row(n, INT_MAX), col(m, INT_MAX);
        dp[n - 1][m - 1] = 1;
        row[n - 1] = 1;
        col[m - 1] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i == n - 1 && j == m - 1) {
                    continue;
                }
                int x = grid[i][j];
                for (int k = j + 1; k <= j + x && k < m; ++k) {
                    dp[i][j] = min(dp[i][j], 1ll + dp[i][k]);
                    if (dp[i][j] <= row[i] + 1ll && row[i] != INT_MAX) {
                        break;
                    }
                }
                row[i] = min(row[i], dp[i][j]);
                for (int k = i + 1; k <= i + x && k < n; ++k) {
                    dp[i][j] = min(dp[i][j], 1ll + dp[k][j]);
                    if (dp[i][j] <= col[j] + 1ll && col[j] != INT_MAX) {
                        break;
                    }
                }
                col[j] = min(col[j], dp[i][j]);
                debug(dp, row, col)
            }
        }
        debug(dp, row, col)
        return (dp[0][0] == INT_MAX ? -1 : dp[0][0]);
    }
    void test(void) {
        vector<vector<int>> t = {{7, 12, 11, 11, 4}, {10, 5, 16, 15, 7}, {7, 9, 6, 16, 7}, {1, 13, 3, 16, 0}};
        cout << minimumVisitedCells(t);
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif