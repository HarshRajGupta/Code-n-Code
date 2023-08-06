#include <bits/stdc++.h>

#include <vector>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
	vector<vector<int>> man(const vector<vector<int>>& grid) {
		vector<vector<int>> dist(grid.size(), vector<int>(grid.size(), 1e9));
		queue<vector<int>> q;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				if (grid[i][j] == 1) {
					dist[i][j] = 0;
					q.push({i, j, 0});
				}
			}
		}
		while (!q.empty()) {
			int i = q.front()[0], j = q.front()[1], d = q.front()[2];
			q.pop();
			if (dist[i][j] < d) continue;
			if (i > 0 && dist[i - 1][j] > d + 1) {
				dist[i - 1][j] = d + 1;
				q.push({i - 1, j, d + 1});
			}
			if (j > 0 && dist[i][j - 1] > d + 1) {
				dist[i][j - 1] = d + 1;
				q.push({i, j - 1, d + 1});
			}
			if (i < grid.size() - 1 && dist[i + 1][j] > d + 1) {
				dist[i + 1][j] = d + 1;
				q.push({i + 1, j, d + 1});
			}
			if (j < grid.size() - 1 && dist[i][j + 1] > d + 1) {
				dist[i][j + 1] = d + 1;
				q.push({i, j + 1, d + 1});
			}
		}
		return dist;
	}
	int dfs(vector<vector<int>>& grid, vector<vector<int>>& dist,
			vector<vector<bool>>& visited, int i = 0, int j = 0, int d = 1e9) {
		if (visited[i][j]) return 1e9;
		visited[i][j] = true;
		int ans = min(d, dist[i][j]);
		if (i == grid.size() - 1 && j == grid.size() - 1) return ans;
		if (i > 0) {
			ans = min(ans, dfs(grid, dist, visited, i - 1, j, dist[i][j]));
		}
		if (j > 0) {
			ans = min(ans, dfs(grid, dist, visited, i, j - 1, dist[i][j]));
		}
		if (i < grid.size() - 1) {
			ans = min(ans, dfs(grid, dist, visited, i + 1, j, dist[i][j]));
		}
		if (j < grid.size() - 1) {
			ans = min(ans, dfs(grid, dist, visited, i, j + 1, dist[i][j]));
		}
		return ans;
	}

   public:
	int maximumSafenessFactor(vector<vector<int>>& grid) {
		auto dist = man(grid);
		vector<vector<bool>> dp(grid.size(), vector<bool>(grid.size(), false));
		debug(dist, grid) return dfs(grid, dist, dp);
	}
	void test() {
		{
			vector<vector<int>> a = {
				{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};
			cout << maximumSafenessFactor(a);
		}
	}
	Solution() {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif