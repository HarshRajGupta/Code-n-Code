#include <bits/stdc++.h>

#include <vector>
using namespace std;

// Prints unique output strings of length n

vector<string> a1, a2;

void func(int pos, vector<set<char>> &arr, string &prev) {
	if (pos == arr.size()) {
		a1.push_back(prev);
		return;
	}
	for (auto &i : arr[pos]) {
		prev += i;
		func(pos + 1, arr, prev);
		prev.pop_back();
	}
}

void func2(vector<set<char>> &a) {
	vector<vector<char>> arr(a.size());
	int n = 1;
	for (int i = 0; i < a.size(); i++) {
		for (auto &j : a[i]) arr[i].push_back(j);
		n *= a[i].size();
	}
	debug(n, arr)
}

signed main(void) {
	int n, k;
	cin >> n >> k;
	vector<set<char>> arr(n);
	string temp;
	for (auto &i : arr) {
		cin >> temp;
		for (auto &j : temp) i.insert(j);
	}
	temp = "";
	func(0, arr, temp);
    func2(arr);
	return 0;
}