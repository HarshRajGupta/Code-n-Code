#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
	const int MOD = 1e9 + 7;
	int cmp(string &low, string &high, string s) {
		if (s.size() < low.size()) return -1;
		if (s.size() > high.size()) return 1;
		if (s < low) return -1;
		if (s > high) return 1;
		return 0;
	}
	map<int, map<int, int>> dp;
	int mid(string &low, string &high, int pos, int prev) {
		if (pos == high.size()) return 0;
		if (dp.find(pos) != dp.end() && dp[pos].find(prev) != dp[pos].end()) {
			return dp[pos][prev];
		}
		int ans = 0;
		if (prev > 0 && prev < 9) {
			ans = (mid(low, high, pos + 1, prev - 1) + 0ll +  mid(low, high, pos + 1, prev + 1)) % MOD;
		} else if (prev == 0) {
			ans = (0ll + mid(low, high, pos + 1, prev + 1)) % MOD;
		} else if (prev == 9) {
			ans = (0ll + mid(low, high, pos + 1, prev - 1)) % MOD;
		}
		if (pos + 1 >= low.size()) {
			ans = (ans + 1) % MOD;
		}
		return dp[pos][prev] = ans;
	}
public:
	int countSteppingNumbers(string low, string high) {
		int ans = 0;
		for (int i = low[0] - '0' + 1; i < high[0] - '0'; ++i) {
			ans = (ans + mid(low, high, 0, i)) % MOD;
		}
		return ans;
	}
	void test() {
		{
			cout << countSteppingNumbers("1", "111");
		}
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