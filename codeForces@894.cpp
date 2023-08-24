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

int d = 1;

int ans(v<int> &a, int pos, int m, int cnt) {
	if (pos == a.size() || !m) {
		return 0;
	}
	int res = ans(a, pos + 1, m - 1, 1) + a[pos] - (d * cnt);
	res = max(res, ans(a, pos + 1, m, cnt + 1));
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m >> d;
	v<int> a(n);
	_for(i, n) cin >> a[i];
	cout << ans(a, 0, m, 1);
}

static void preCompute() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

/**
 * @ScratchPad
 */

__MAIN__