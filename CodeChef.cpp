#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> ans = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), 0));
        for (int k = 0; k < grid[0].size(); ++k) {
            unordered_map<int, int> mp, mp2;
            int i = k, j = k, count = 0, pre = 0;
            while (i < grid.size() && j < grid[0].size()) {
                mp[grid[i][j]]++;
                if (mp[grid[i][j]] == 1) {
                    count++;
                }
                i++;
                j++;
            }
            i = k, j = k;
            while (i < grid.size() && j < grid[0].size()) {
                debug(i, j, count, pre)
                mp[grid[i][j]]--;
                if (mp[grid[i][j]] == 0) {
                    count--;
                }
                ans[i][j] = abs(count - pre);
                mp2[grid[i][j]]++;
                if (mp2[grid[i][j]] == 1) {
                    pre++;
                }
                i++; j++;
            }
        }
        return ans;
    }
    void test() {
        /* test */
        vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
        vector<vector<int>> ans = differenceOfDistinctValues(grid);
        debug(ans)
    }
};

#ifdef __TEST__
__TEST__
#endif