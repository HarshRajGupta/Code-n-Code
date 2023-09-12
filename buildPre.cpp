#include <bits/stdc++.h>
#include <iostream>
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
		debug(i, ans);
	}

	return ans;
}

signed main(void) {
	int n; cin >> n;
	vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        arr[i] = s;
    }
    debug(arr);
	cout << fun(arr) << endl;

	return 0;
}