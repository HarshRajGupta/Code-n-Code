#include <bits/stdc++.h>
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

signed main(void) {
	int n;
	string s;
	cin >> n >> s;
	cout << ans(n, s) << endl;

	return 0;
}