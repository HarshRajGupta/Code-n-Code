#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    int findWays(vector<int>& arr, int k) {
        int dp[arr.size() + 1][k + 1] = {0};
        for (int i = arr.size() - 1; i >= 0; --i) {
            for (int j = 0; j <= k; ++j) {
                if (i == 0) {
                    dp[i][j] = 1;
                }
                dp[i][j] += dp[i + 1][j];
                if (j >= arr[i]) dp[i][j] += dp[i + 1][j - arr[i]];
            }
        }
        return dp[0][k];
    }
    void test() {
        vector<int> a = {1, 4, 4, 5};
        cout << findWays(a, 5);
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