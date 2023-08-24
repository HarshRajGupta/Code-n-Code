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

const int ub(const vector<int> &arr, int t, int l = 0, int r = -1) {
	if (r == -1) r = (arr.size() - 1);
	if (t < arr[l])
		return l;
	else if (t >= arr[r])
		return r + 1;
	int ans = r + 1, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (arr[mid] <= t)
			l = (mid + 1);
		else
			ans = mid, r = (mid - 1);
	}
	return ans;
}

const int lb(const vector<int> &arr, int t, int l = 0, int r = -1) {
	if (r == -1) r = (arr.size() - 1);
	if (arr[l] >= t)
		return l - 1;
	else if (arr[r] < t)
		return r;
	int ans = l - 1, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (arr[mid] >= t)
			r = (mid - 1);
		else
			ans = mid, l = (mid + 1);
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	v<int> a(n);
	_for(i, n) cin >> a[i];
	reverse(all(a));
	v<int> ans(n);
	_for(i, n) {
		int z = lb(a, i + 1);
		debug(i, z);
		ans[i] = z;
	}
	debug(a, ans)
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