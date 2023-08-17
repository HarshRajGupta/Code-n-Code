#include <bits/stdc++.h>

#include <string>
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

bool isSubstr(string &a, string &b) {
	string t(a.begin(), a.begin() + b.size());
	for (int i = 0; i < b.size(); ++i) {
		if (t == b) return true;
		t.erase(t.begin());
		t += a[i + b.size()];
	}
	if (t == b) return true;
	return false;
}

void solve() {
	string s;
	cin >> s;
	string a("()", s.size());
	string tt('a', 10);
	string b = string('(', s.size()) + string(')', s.size());
	debug(s, tt);
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