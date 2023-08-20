#include <bits/stdc++.h>

#include <deque>
#include <vector>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
	map<int, map<int, int>> mod;
	string l, r;
	int k;
	int dp[12][12][12][21][2][2];
	int cnt(int pos, int even, int odd, int rem, bool isLow, bool started) {
		if (pos == r.size()) {
			return ((rem == 0) && (even == odd));
		}
		if (dp[pos][even][odd][rem][isLow][started] != -1)
			return dp[pos][even][odd][rem][isLow][started];
		int ans = 0;
		int R = 10;
		if (!isLow) {
			R = r[pos] - '0';
			if (R & 1) {
				ans +=
					cnt(pos + 1, even, odd + 1,
						(rem + (mod[R][r.size() - pos - 1])) % k, isLow, false);
			} else {
				ans +=
					cnt(pos + 1, even + 1, odd,
						(rem + (mod[R][r.size() - pos - 1])) % k, isLow, false);
			}
		}
		for (int i = l[pos] - '0'; i < R; i++) {
			if (i & 1) {
				ans +=
					cnt(pos + 1, even, odd + 1,
						(rem + (mod[i][r.size() - pos - 1])) % k, true, false);
			} else if (i == 0 && started) {
				ans += cnt(pos + 1, even, odd, rem, isLow, true);
			} else {
				ans +=
					cnt(pos + 1, even + 1, odd,
						(rem + (mod[i][r.size() - pos - 1])) % k, true, false);
			}
		}
		debug(pos, even, odd, rem, isLow, ans);
		return dp[pos][even][odd][rem][isLow][started] = ans;
	}

   public:
	int numberOfBeautifulIntegers(int low, int high, const int K) {
        memset(dp, -1, sizeof(dp));
		k = K;
		l = "", r = "";
		int n = log10(high) + 1;
		for (int i = 0; i < (n); ++i) {
			l.push_back('0' + low % 10);
			r.push_back('0' + high % 10);
			low /= 10;
			high /= 10;
		}
		reverse(l.begin(), l.end());
		reverse(r.begin(), r.end());
		debug(l, r);
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; j++) {
				long long t = i * 1ll * (int)pow(10, j);
				mod[i][j] = (t) % K;
			}
		}
		return cnt(0, 0, 0, k, false, true);
	}
	void test() { cout << numberOfBeautifulIntegers(9, 25, 4); }
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