#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    const int MOD = 1e9 + 7;
    int steppingNumbers(vector<vector<vector<int>>> &dp, string r, int pos,
                        int val, bool isLow) {
        if (pos == r.size()) return 1;
        if (dp[pos][val][isLow] != -1) return dp[pos][val][isLow];
        if (isLow) {
            int ans = 0;
            if (val > 0) {
                ans = (ans + steppingNumbers(dp, r, pos + 1, val - 1, true)) %
                      MOD;
            }
            if (val < 9) {
                ans = (ans + steppingNumbers(dp, r, pos + 1, val + 1, true)) %
                      MOD;
            }
            return dp[pos][val][isLow] = ans;
        }
        if (pos + 1 == r.size()) {
            return dp[pos][val][isLow] = 1;
        }
        int ans = 0;
        if (val > 0) {
            if (val - 1 > r[pos + 1] - '0') {
                return dp[pos][val][isLow] = 0;
            }
            ans = (ans + steppingNumbers(dp, r, pos + 1, val - 1,
                                         (r[pos + 1] - '0') < (val - 1))) %
                  MOD;
        }
        if (val < 9) {
            if (val + 1 > r[pos + 1] - '0') {
                return dp[pos][val][isLow] = ans;
            }
            ans = (ans + steppingNumbers(dp, r, pos + 1, val + 1,
                                         (r[pos + 1] - '0') < (val + 1))) %
                  MOD;
        }
        return dp[pos][val][isLow] = ans;
    }

public:
    int stepping(string s) {
        vector<vector<vector<int>>> dp(
            s.size(), vector<vector<int>>(10, vector<int>(2, -1)));
        int ans = 0;
        for (int i = 0; i < s[0] - '0'; ++i) {
            ans = (ans + steppingNumbers(dp, s, 0, i, true)) % MOD;
        }
        ans = (ans + steppingNumbers(dp, s, 0, s[0] - '0', false)) % MOD;
        debug(dp)
        return ans;
    }
    int countSteppingNumbers(string low, string high) {
        int a = stepping(low), b = stepping(high);
        return (b - a + MOD) % MOD;
    }
    void test() {
        cout << countSteppingNumbers("11", "111111");
    }
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif