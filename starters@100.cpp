#include <bits/stdc++.h>

#include <vector>
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

vector<bool> isPrime(100008, true);
vector<bool> sieve(const int32_t n = 100007) {
	isPrime[0] = false, isPrime[1] = false;
	for (int32_t i = 2; (i * i) <= n; ++i)
		if (isPrime[i])
			for (int j = (i * i); j <= n; j += i) isPrime[j] = false;
	return isPrime;
}

void solve() {
	int n;
	cin >> n;
	if (isPrime[n - 2]) {
		_for(i, n - 2) { cout << i + 3 << ' '; }
		cout << "1 2";
	} else if (isPrime[n - 3]) {
		_for(i, n - 3) { cout << i + 4 << ' '; }
		cout << "1 2 3";
	} else{
		cout << -1;
	}
}

static void preCompute() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve();
}

/**
 * @ScratchPad
 */

__MAIN__