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
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        set<pair<int, int>> row[n], col[m];
        dp[n - 1][m - 1] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int x = grid[i][j];
                for (auto k : row[i]) {
                    if (k.second <= j + x) {
                        dp[i][j] = 1 + k.first;
                        break;
                    }
                }
                for (auto k : col[j]) {
                    if (k.second <= i + x) {
                        dp[i][j] = min(dp[i][j], 1 + k.first);
                        break;
                    }
                }
                row[i].insert({dp[i][j], j});
                col[j].insert({dp[i][j], i});
            }
        }
        // debug(dp, row, col)
        return (dp[0][0] == 1e9 ? -1 : dp[0][0]);
    }
    void test(void) {
        // cout << minimumVisitedCells(grid);
    }
};

#ifdef __TEST__
__TEST__
#endif