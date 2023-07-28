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

int dfs(v<v<int>> &graph, v<int> &cost, v<bool> &visited, int src) {
	if (visited[src]) return cost[src];
	int ans = cost[src];
	visited[src] = true;
	foreach (i, graph[src]) {
		int temp = dfs(graph, cost, visited, i);
		if (temp >= 0) {
			if (ans < 0) ans = temp;
			else ans = min(ans, temp);
		}
	}
	return ans;
}

void solve(void) {
	int n, m; cin >> n >> m;
	v<v<int>> graph(n);
	v<int> cost(n);
	debug(n, m)
	_for(i, m) {
		int u, v; cin >> u >> v;
		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}
	// foreach(i, cost) cin >> i;
	debug(cost, graph);
	v<bool> visited(n, false);
	int ans = 0;
	_for(i, n) {
		if (visited[i]) continue;
		int temp = dfs(graph, cost, visited, i);
		if (temp >= 0) ans += temp;
		else {
			cout << "-1";
			return;
		}
	}
	cout << ans;
}

/**
 * @ScratchPad
 */

__SOLVE__