#include <bits/stdc++.h>

#include <climits>
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

bool fun(v<int> &arr, int x, const int h) {
	int H = 0;
	foreach (i, arr) {
		if (i > x) {
			H += i;
		}
	}
	debug(x, H, h)
	return H < h;
}

void solve() {
	int n, h;
	cin >> n >> h;
	v<int> arr(n);
	foreach (i, arr) cin >> i;
	int l = 0, r = INT_MAX, ans = INT_MAX;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (fun(arr, mid, h)) {
			ans = min(ans, mid);
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans;
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