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

int ans(string &s, string &k, int pos) {
	int res = 0;
	for (int i = 0; i < k.size(); ++i) {
		res += min(9 - s[pos + i] + k[i], abs(s[pos + i] - k[i]));
	}
	return res;
}

void solve() {
	int n, m;
	string s, k;
	cin >> n >> m >> s >> k;
	int res = INT_MAX;
	for (int i = 0; i <= n - m; ++i) {
		res = min(res, ans(s, k, i));
	}
	cout << res;
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