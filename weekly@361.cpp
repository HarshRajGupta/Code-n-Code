#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
	int check(string &num, string &t, int i, int j) {
		if (j < 0 || i < 0) return 0;
		if (num[i] == t[j]) return check(num, t, i - 1, j - 1);
		return check(num, t, i - 1, j) + 1;
	}

   public:
	int minimumOperations(string &num) {
		int ans = num.size();
		string t = "00";
		ans = min(ans, check(num, t, num.size() - 1, 1));
		debug(ans);
		t = "50";
		ans = min(ans, check(num, t, num.size() - 1, 1));
		debug(ans);
		t = "25";
		ans = min(ans, check(num, t, num.size() - 1, 1));
		debug(ans);
		t = "75";
		ans = min(ans, check(num, t, num.size() - 1, 1));
		debug(ans);
		return ans;
	}
	void test() {
		{
			string t = "5";
			debug(minimumOperations(t));
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