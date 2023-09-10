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
	for (int i = 0; i < n; i++) {
		string temp = "";
		int N = i;
		for (int j = 0; j < a.size(); j++) {
			temp += arr[j][N % arr[j].size()];
			N /= arr[j].size();
		}
		a2.push_back(temp);
	}
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
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	if (a1 == a2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}