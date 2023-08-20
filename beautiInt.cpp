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
	int cnt(int pos, int even, int odd, int rem, bool isLow,
			bool started = false) {
		debug(pos, even, odd, rem, isLow);
		if (pos == r.size()) {
			if ((rem == 0) && (even == odd)) return 1;
			return 0;
		}
		int ans = 0;
		if (isLow) {
			for (int i = l[pos] - '0'; i <= r[pos] - '0'; i++) {
				if (i & 1)
					ans += cnt(pos + 1, even, odd + 1,
							   (rem + (mod[i][r.size() - pos - 1])) % k, isLow);
				else
					ans += cnt(pos + 1, even + 1, odd,
							   (rem + (mod[i][r.size() - pos - 1])) % k, isLow);
			}
		} else {
			if (l[pos] == r[pos] && l[pos] == '0' && started) {
				return cnt(pos + 1, even, odd, rem, false, true);
			}
			for (int i = l[pos] - '0'; i < r[pos] - '0'; i++) {
				if (i & 1)
					ans += cnt(pos + 1, even, odd + 1,
							   (rem + (mod[i][r.size() - pos - 1])) % k, true);
				else
					ans += cnt(pos + 1, even + 1, odd,
							   (rem + (mod[i][r.size() - pos - 1])) % k, true);
			}
			if ((r[pos] - '0') & 1)
				ans += cnt(pos + 1, even, odd + 1,
						   (rem + (mod[r[pos] - '0'][r.size() - pos - 1])) % k,
						   false);
			else
				ans += cnt(pos + 1, even + 1, odd,
						   (rem + (mod[r[pos] - '0'][r.size() - pos - 1])) % k,
						   false);
		}

		return ans;
	}

   public:
	int numberOfBeautifulIntegers(int low, int high, const int K) {
		k = K;
		l = "", r = "";
		for (int i = 0; i < 9; ++i) {
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
	void test() { cout << numberOfBeautifulIntegers(10, 20, 3); }
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