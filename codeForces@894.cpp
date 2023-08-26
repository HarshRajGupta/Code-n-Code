#include <bits/stdc++.h>
using namespace std;

signed main(void) {
	int n;
	cin >> n;
	vector<int> range(n + 1), cost(n + 1);
	for (auto &i : range) cin >> i;
	for (auto &i : cost) cin >> i;
	vector<multiset<int>> inc(n + 1), dec(n + 1);
	for (int i = 0; i <= n; ++i) {
		int l = max(i - range[i], 0), r = min(i + range[i] + 1, n);
		inc[l].insert(cost[i]);
		dec[r].insert(cost[i]);
	}
	debug(inc, dec);
	int ans = 0;
	multiset<int> s = inc[0];
	for (auto &j : dec[0]) s.erase(s.find(j));
	for (int i = 1; i <= n; ++i) {
		for (auto &j : dec[i - 1]) s.erase(s.find(j));
		for (auto &j : inc[i]) s.insert(j);
		if (s.size())
			ans += (*s.begin());
		else {
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}