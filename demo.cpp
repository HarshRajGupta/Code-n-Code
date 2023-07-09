#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    int dfs(vector<vector<int>>& mat, vector<vector<int>> &ans, int i, int j) {
        if ((i < 0) || (i >= mat.size()) || (j < 0) || (j >= mat[0].size()))
            return 1e5;
        debug(i, j)
        if (mat[i][j] == 0)
            return (ans[i][j] = 0);
        if (ans[i][j] != -1)
            return ans[i][j];
        return min(
                   min(
                       dfs(mat, ans, i, j + 1),
                       dfs(mat, ans, i, j - 1)
                   ),
                   min(
                       dfs(mat, ans, i + 1, j),
                       dfs(mat, ans, i - 1, j)
                   )
               ) + 1;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), -1));
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (ans[i][j] == -1)
                    dfs(mat, ans, i, j);
            }
        }
        return ans;
    }
    void test() {
        vector<vector<int>> a = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
        debug(updateMatrix(a))
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif