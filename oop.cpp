#include <bits/stdc++.h>
#include <string>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
	vector<char> word = {'W', 'O', 'R', 'D'};

   public:
	int ans(string s, int pos = 0, int prev = 0) {
		if (pos == s.size()) {
			if (prev == 3) return 0;
			return -1;
		}
		if (prev == 3) {
			int res = ans(s, pos + 1, prev);
			if (res == -1) return (s[pos] == word[prev]);
			return res + (s[pos] == word[prev]);
		}
		if (s[pos] == word[prev]) {
			int res = ans(s, pos + 1, prev);
			if (res == -1) return -1;
			return res + 1;
		}
		if (s[pos] == word[prev + 1]) {
			int res = ans(s, pos + 1, prev + 1);
			if (res == -1) return -1;
			return res + 1;
		}
		return ans(s, pos + 1, prev);
	}
	void test() {
		string s = "WWWOOORRRDDDDEEE";
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