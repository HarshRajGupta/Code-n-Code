#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void isPalindrome(const string &ans) {
	int i = 0, j = ans.length() - 1;
	while (i < j) {
		if (ans[i] != ans[j]) return;
		i++;
		j--;
	}
	cnt++;
	cout << ans << ",";
}

void ans(string &prev, vector<string> &arr) {
	if (prev.length() == 9) isPalindrome(prev);
	if (prev.length() >= 9) return;
	for (auto &i : arr) {
		string temp = prev + i;
		ans(temp, arr);
	}
}

signed main(void) {
	int n;
	cin >> n;
	vector<string> arr(n);
	for (auto &i : arr) cin >> i;
	string temp = "";
	ans(temp, arr);
	debug(cnt);
	return 0;
}