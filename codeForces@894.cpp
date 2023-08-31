#include <bits/stdc++.h>
using namespace std;

void func(int pos, vector<set<char>> &arr, string &prev) {
	if (pos == arr.size()) {
		cout << prev << ' ';
		return;
	}
	for (auto &i : arr[pos]) {
		prev += i;
		func(pos + 1, arr, prev);
		prev.pop_back();
	}
}

signed main(void) {
	int n, k;
	cin >> n >> k;
	vector<set<char>> arr(n);
	string temp;
	for (auto &i : arr) {
		cin >> temp;
		for (auto &j : temp) {
			i.insert(j);
		}
	}
	temp = "";
	func(0, arr, temp);
	return 0;
}