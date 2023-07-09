#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 1e9));
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        queue<pair<vector<int>, int>> q;
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                if (!mat[i][j]) q.push({{i, j}, 0});
            }
        }
        while (!q.empty()) {
            auto &[p, v] = q.front();
            int x = p[0], y = p[1];
            q.pop();
            debug(x, y, v)
            ans[x][y] = v;
            if (x > 0 && v + 1 < ans[x - 1][y]) q.push({{x - 1, y}, v + 1});
            if (y > 0 && v + 1 < ans[x][y - 1]) q.push({{x, y - 1}, v + 1});
            if (x < mat.size() - 1 && v + 1 < ans[x + 1][y]) q.push({{x + 1, y}, v + 1});
            if (y < mat[0].size() - 1 && v + 1 < ans[x][y + 1]) q.push({{x, y + 1}, v + 1});
        }
        return ans;
    }
    void test() {
        vector<vector<int>> a = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
        debug(updateMatrix(a))
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif