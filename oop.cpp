#include <bits/stdc++.h>

#include <climits>
#include <string>
#include <vector>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

vector<char> word = {'W', 'O', 'R', 'D'};
vector<vector<int>> dp(200, vector<int>(7, -2));
int ans(string s, int pos = 0, int prev = 0) {
	if (pos == s.size()) {
		if (prev == 3) return 0;
		return -1;
	}
	if (dp[pos][prev] != -2) return dp[pos][prev];
	if (prev == 3) {
		int res = ans(s, pos + 1, prev);
		if (res == -1) return dp[pos][prev] = (s[pos] == word[prev]);
		return dp[pos][prev] = res + (s[pos] == word[prev]);
	}
	if (s[pos] == word[prev]) {
		int res = ans(s, pos + 1, prev);
		if (res == -1) return dp[pos][prev] = -1;
		return dp[pos][prev] = res + 1;
	}
	if (s[pos] == word[prev + 1]) {
		int res = ans(s, pos + 1, prev + 1), res2 = ans(s, pos + 1, prev);
		if (res == -1 && res2 == -1) return dp[pos][prev] = -1;
		return dp[pos][prev] = max(res + 1, res2);
	}
	return dp[pos][prev] = ans(s, pos + 1, prev);
}
class Solution {
   public:
	void test() {
		string s = "777WWOWOOORDRRDDDEEEE";
		cout << ans(s);
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