#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __MAIN__
#define __MAIN__                           \
	signed main() {                        \
		preCompute();                      \
		signed t;                          \
		cin >> t;                          \
		while (t--) solve(), cout << '\n'; \
		return 0;                          \
	}
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define _for(i, n) for (int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for (int32_t i = a; i < (int32_t)n; ++i)
#define foreach(i, x) for (auto &i : x)

template <class T>
using v = vector<T>;
template <class T>
using maxHeap = priority_queue<T>;
template <class T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve() {
	int m, k, a, b;
	cin >> m >> k >> a >> b;
	if (k * b >= m) {
		if (m % k <= a) {
			cout << 0;
		} else {
			cout << (m % k - a);
		}
	} else {
		if ((k * b) + a >= m) {
			cout << 0;
		} else {
			int diff = m - ((k * b));
			int ans = (diff / k) + (diff % k <= a ? 0 : diff % k - a);
			if (((int)((diff / k) + 1) * k) <= diff) {
				int t = (diff / k) + 1;
				int ANS = t;
				if ((diff - (t * k)) > a) ANS += (diff - (t * k)) - a;
				ans = min(ans, ANS);
			}
			cout << ans;
		}
	}
}

static void preCompute() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

/**
 * @ScratchPad
 * (diff - (((diff / k) + 1) * k)) <= a ? ((diff / k) + 1): ((diff / k) + 1) +
 * (diff - (((diff / k) + 1) * k) - a
 */

__MAIN__