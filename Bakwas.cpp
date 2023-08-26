#include <bits/stdc++.h>
using namespace std;

bool visited[1001][1001];

void dfs(vector<vector<int>> &graph, int x, int y, int i, int j, int z) {
	if (i < 0 || i >= graph.size() || j < 0 || j >= graph[0].size()) return;
	if (visited[i][j]) return;
	visited[i][j] = true;
	long double dist = sqrt((x - i) * (x - i) + (y - j) * (y - j));
	if (dist <= z) {
		debug(x, y, i, j, dist)
		graph[i][j] = 0;
		dfs(graph, x, y, i + 1, j, z);
		dfs(graph, x, y, i - 1, j, z);
		dfs(graph, x, y, i, j + 1, z);
		dfs(graph, x, y, i, j - 1, z);
	}
}

signed main(void) {
	int n, m, k, t, r;
	cin >> n >> m >> k;
	vector<pair<int, int>> adj(k);
	for (auto &i : adj) cin >> i.first >> i.second;
	cin >> r >> t;
	vector<vector<int>> graph(n + 1, vector<int>(m + 1, 1));
	for (int i = 0; i < k; ++i) {
		memset(visited, false, sizeof(visited));
		int x = adj[i].first, y = adj[i].second, z = r * t;
		dfs(graph, x, y, x, y, z);
	}
	int ans = 0;
	for (auto &i : graph) {
		for (auto &j : i) {
			if (j) ans++;
		}
	}
	debug(graph)
	cout << ans;
	return 0;
}