#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3", "fast-math", "unroll-loops", "no-stack-protector", \
                         "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "sse4", "abm", "mmx", "avx", "avx2")
#endif

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
	int r, c, k; cin >> r >> c >> k;
	vector<vector<bool>> grid(8, vector<bool>(8, false));
	queue<pair<int, int>> q;
	int ans = 0;
	q.push({r - 1, c - 1});
	while (!q.empty()) {
		auto [i, j] = q.front();
		q.pop();
		if ((i < 0) || (j < 0) || (i >= 8) || (j >= 8) || (grid[i][j])) continue;
		grid[i][j] = true;
		q.push({i - 1, j});
		q.push({i, j - 1});
		q.push({i + 1, j});
		q.push({i, j + 1});
		++ans;
	}
	cout << ans;
}

static void preCompute() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.flush();

}

/**
 * @ScratchPad
 */

__MAIN__