#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
map<int, map<int, int>> dp;

int countSubset(vector<int> &arr, int pos, int target) {
	if (target == 0) return 1;
	if (pos >= arr.size() || arr[pos] > target) return 0;
	if (dp.find(pos) != dp.end() && dp[pos].find(target) != dp[pos].end())
		return dp[pos][target];
	int ans = 0;
	for (int i = 0; i <= mp[arr[pos]]; i++)
		ans += countSubset(arr, pos + 1, target - (arr[pos] * i));
	return dp[pos][target] = ans;
}

signed main(void) {
	int n, x;
	cin >> n >> x;
	set<int> a;
	for (int i = 0, t; i < n; i++) {
		cin >> t;
		mp[t]++;
		a.insert(t);
	}
	vector<int> arr(a.begin(), a.end());
	cout << countSubset(arr, 0, x) << endl;
	return 0;
}