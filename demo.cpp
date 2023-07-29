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

#ifndef __SOLVE__
#define __SOLVE__   \
	signed main() { \
		solve();    \
		return 0;   \
	}
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;

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

void solve(void) {
	int n, m;
	cin >> n >> m;
	v<v<int>> graph(n), revGraph(n);
	_for(i, m) {
		int u, v;
		cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		revGraph[v - 1].push_back(u - 1);
	}
	v<int> dist(n, 1e6);
	minHeap<pair<int, int>> q;
	q.push({0, 0});
	while (!q.empty()) {
		auto [cost, node] = q.top();
		q.pop();
		for (auto &i : graph[node]) {
			if (dist[i] > cost) {
				dist[i] = cost;
				q.push({cost, i});
			}
		}
		for (auto &i : revGraph[node]) {
			if (dist[i] > cost + 1) {
				dist[i] = cost + 1;
				q.push({cost + 1, i});
			}
		}
	}
	if (dist[n - 1] == 1e6)
		cout << -1;
	else
		cout << dist[n - 1];
}

/**
 * @ScratchPad
 */

__SOLVE__