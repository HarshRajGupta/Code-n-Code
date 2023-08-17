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
	int n, ans = 0;
	cin >> n;
	v<int> arr(n);
	foreach (i, arr) cin >> i;
	set<int> s;
	s.insert(arr[0]);
	v<int> parity(n + 1);
	for (int i = 1; i < n; ++i) {
		auto it = s.lower_bound(arr[i]);
		bool b = (*it < arr[i]);
		if (*it < arr[i]) {
			parity[arr[i]] = parity[*it] + 1;
			if (parity[arr[i]] == 1) ans++;
		}
		s.insert(arr[i]);
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