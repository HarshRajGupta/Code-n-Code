#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#ifndef __SOLVE__
#define __SOLVE__ ios_base::sync_with_stdio(0);cin.tie(NULL);solve();return 0;
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;

#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)
#define bw(i, n) for(int32_t i = n; i >= 0; --i)

template <class T> using v = std::vector<T>;
template <class T> using maxHeap = std::priority_queue<T>;
template <class T> using minHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve(void) {
	int n; cin >> n;
	v<int> a(n), A(n);
	_for(i, n) {
		int t; cin >> t;
		a[t - 1] = i;
	}
	int m = 0; cin >> m;
	v<int> b(m), B(m);
	_for(i, m) {
		int t; cin >> t;
		b[t - 1] = i;
	}
	int k; cin >> k;
	debug(a, b)
	while (k--) {
		int l, r; cin >> l >> r;
		debug(l, r)
		if (A[l - 1] || B[r - 1]) continue;
		if ((l ^ r) & 1) {
			A[r - 1] = 1;
			--m;
		} else {
			B[l - 1] = 1;
			--n;
		}
	}
	if (m > n) {
		cout << "Ramadhir";
	} else
		cout << "Sardar";
}

signed main(void) {__SOLVE__}