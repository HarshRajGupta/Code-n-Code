#include <bits/stdc++.h>
using namespace std;

int func(vector<int> &arr) {
	int ans = 1, count = 1;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] == arr[i - 1] + 1)
			++count;
		else
			count = 1;
		ans = max(ans, count);
	}
	return ans;
}

signed main(void) {
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cout << func(arr) << endl;
	return 0;
}