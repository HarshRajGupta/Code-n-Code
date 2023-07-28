#include <bits/stdc++.h>
using namespace __gnu_debug;
using namespace std;

#ifndef debug
#define debug(...)
#endif

class Solution {
    const int MOD = 1e9 + 7;
    const int power(int n, int expo) {
        int ans = 1; n %= MOD;
        while (expo) {
            if (expo & 1) ans = (ans * 1ll * n) % MOD;
            n = (n * 1ll * n) % MOD;
            expo >>= 1;
        }
        return ans;
    }
    int numberOfWays(vector<vector<int>> &dp, int n, int x, int prev) {
        if (n == 0) return 1;
        if (dp[n][prev] != -1) return dp[n][prev];
        int ans = 0;
        for (int i = prev + 1; i <= n; ++i) {
            int pow = power(i, x);
            if (pow > n) break;
            ans = (ans + numberOfWays(dp, n - pow, x, i)) % MOD;
        }
        return dp[n][prev] = ans;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 7, vector<int>(n + 7, -1));
        return numberOfWays(dp, n, x, 0);
    }

    void test() {
        /* test */
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