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

int z(int m, int k, int a, int b) {
	int diff = m - ((k * b));
	if (a >= k) {
		diff -= (a - (a % k));
		a = a % k;
	}
	return (diff / k) + (diff % k <= a ? 0 : diff % k - a);
}

int zz(int m, int k, int a, int b) {
	int diff = m - ((k * b));
	if (a >= k) {
		diff -= (a - (a % k) - k);
		a = (a % k) + k;
	}
	return (diff / k) + (diff % k <= a ? 0 : diff % k - a);
}

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
			// int diff = m - ((k * b));
			// if (a >= k) {
			// 	diff -= (a - (a % k));
			// 	a = a % k;
			// }
			// int ans = (diff / k) + (diff % k <= a ? 0 : diff % k - a);
			// debug(diff / k, diff % k);
			int ans = min(z(m, k, a, b), zz(m, k, a, b));
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