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
	int n; cin >> n;
	v<int> inDegree(n);
	v<v<int>> tree(n);
	_for(i, n - 1) {
		int u, v; cin >> u >> v;
		u--; v--;
		tree[u].push_back(v);
		inDegree[v]++;
	}
	int ans = 0;
	minHeap<pair<int, int>> q;
	_for(i, n) {
		q.push({inDegree[i], i});
	}
	v<bool> visited(n);
	while (!q.empty()) {
		debug(q)
		auto [cost, u] = q.top();
		q.pop();
		if (visited[u]) continue;
		visited[u] = true;
		ans += cost;
		foreach (v, tree[u]) {
			if (visited[v]) continue;
			--inDegree[v];
			q.push({inDegree[v], v});
		}
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