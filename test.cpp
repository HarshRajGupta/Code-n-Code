#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    vector<int> dp[2] = {vector<int>(5001, -1), vector<int>(5001, -1)};
    int maxProfitAtI(vector<int>& prices, int pos = 0, bool flag = false) {
        // debug(pos, flag, dp[0], dp[1])
        if (pos == prices.size()) return 0;
        if (dp[flag][pos] != -1) return dp[flag][pos];
        if (flag) {
            return dp[flag][pos] = max(
                                       maxProfitAtI(prices, pos + 1, true),
                                       prices[pos] + maxProfitAtI(prices, pos + 2, false)
                                   );
        }
        return dp[flag][pos] = max(
                                   maxProfitAtI(prices, pos + 1, false),
                                   maxProfitAtI(prices, pos + 1, true) - prices[pos]
                               );
    }
public:
    int maxProfit(vector<int>& prices) {
        return maxProfitAtI(prices);
    }
    void test() {
        vector<int> a = {1,2,3,0,2};
        debug(maxProfitAtI(a))
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