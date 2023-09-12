#include <bits/stdc++.h>

#include <string>
#include <vector>
using namespace std;

int ans(int n, string s) {
	int G = 0, count = 0;
	for (auto &i : s) {
		if (i == 'G')
			++G;
		else if (G) {
			++count;
			--G;
		}
	}
	return count;
}

string fun(vector<string> &arr) {
	map<string, int> mp;
	for (auto &i : arr) ++mp[i];
	string ans = "";
	for (auto &i : mp) {
		if (i.second > mp[ans])
			ans = i.first;
		else if (i.second == mp[ans] && i.first < ans)
			ans = i.first;
	}
	return ans;
}

signed main(void) {
	int n;
	vector<string> arr(n);
	for (auto &i : arr) cin >> i;
	cout << fun(arr) << endl;

	return 0;
}