// O(VlogV + ElogV)
// Single Source Shortest Path
#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> dijkstra(const vector<vector<pair<int, long long>>> &adj, const int source = 0) {
	vector<vector<long long>> result = {vector<long long>(adj.size(), LLONG_MAX), vector<long long>(adj.size(), -1)};
	result[0][source] = 0;
	priority_queue <pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
	q.push({0, source});
	while (!q.empty()) {
		pair<long long, int> here = q.top();
		q.pop();
		int v = here.second;
		long long d_v = here.first;
		if (d_v != result[0][v])
			continue;
		for (auto edge : adj[v]) {
			if (result[0][v] + edge.second < result[0][edge.first]) {
				result[0][edge.first] = result[0][v] + edge.second;
				result[1][edge.first] = v;
				q.push({result[0][edge.first], edge.first});
			}
		}
	}
	/*
		result[0] == Distance (stores the shortest path from source to every vertex)
		result[1] == Parent (stores the shortest path tree)
	*/
	return result;
}