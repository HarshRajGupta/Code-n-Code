#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
	const int MOD = 1e9 + 7;
	int dp[107][11][2];
	int stepping(string s, int n, int prev, bool isLow) {
		if (n == s.size()) return prev > 0;
		if (dp[n][prev + 1][isLow] != -1) return dp[n][prev + 1][isLow];
		if (prev == -1) {
			if (n) {
				int ans = 0;
                ans = (ans + stepping(s, n + 1, -1, true)) % MOD;
				for (int i = 1; i < 10; ++i) {
					ans = (ans + stepping(s, n + 1, i, true)) % MOD;
				}
				debug(s, n, prev, isLow, ans);
				return dp[n][prev + 1][isLow] = ans;
			}
			int ans = 0;
			for (int i = -1; i < (s[0] - '0'); ++i) {
				ans = (ans + stepping(s, n + 1, i, true)) % MOD;
			}
			ans = (ans + stepping(s, n + 1, s[0] - '0', false)) % MOD;
            debug(s, n, prev, isLow, ans);
			return dp[n][prev + 1][isLow] = ans;
		}
		if (isLow) {
			int ans = 0;
			if (prev > 0) {
				ans = (ans + stepping(s, n + 1, prev - 1, true)) % MOD;
			}
			if (prev < 9) {
				ans = (ans + stepping(s, n + 1, prev + 1, true)) % MOD;
			}
            debug(s, n, prev, isLow, ans);
			return dp[n][prev + 1][isLow] = ans;
		}
		int ans = 0;
		if (prev > 0) {
			if ((prev - 1) > s[n] - '0') {
                debug(s, n, prev, isLow, ans);
				return dp[n][prev + 1][isLow] = 0;
			}
			ans = (ans +
				   stepping(s, n + 1, prev - 1, (s[n] - '0') < (prev - 1))) %
				  MOD;
		}
		if (prev < 9) {
			if (prev + 1 > s[n] - '0') {
                debug(s, n, prev, isLow, ans);
				return dp[n][prev + 1][isLow] = ans;
			}
			ans = (ans +
				   stepping(s, n + 1, prev + 1, (s[n] - '0') < (prev + 1))) %
				  MOD;
		}
        debug(s, n, prev, isLow, ans);
		return dp[n][prev + 1][isLow] = ans;
	}

   public:
	int countSteppingNumbers(string low, string high) {
		memset(dp, -1, sizeof(dp));
		int LOW = stepping(low, 0, -1, false);
		memset(dp, -1, sizeof(dp));
		int HIGH = stepping(high, 0, -1, false);
		cout << LOW << ' ' << HIGH << endl;
		return (HIGH - LOW + MOD) % MOD;
	}
	void test() { cout << countSteppingNumbers("1", "100"); }
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