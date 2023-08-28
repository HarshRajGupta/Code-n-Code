#include <bits/stdc++.h>
using namespace std;

vector<int> fun(int n, vector<string> &logs) {
	vector<vector<vector<int>>> timeStamp(3007);
	for (auto &i : logs) {
		int id = 0, j = 0, time = 0;
		while (i[j] != ':') id = (id * 10) + i[j++] - '0';
		j++;
		string type = "";
		while (i[j] != ':') type += i[j++];
		j++;
		while (j < i.size()) time = (time * 10) + i[j++] - '0';
		timeStamp[time].push_back({id, type == "start"});
	}
	vector<int> ans(n, 0);
	stack<int> st;
	for (int i = 0; i < 3007; i++) {
		if (timeStamp[i].empty()) {
			if (!st.empty()) ans[st.top()]++;
		} else {
			for (auto &j : timeStamp[i]) {
				ans[j[0]]++;
				if (j[1])
					st.push(j[0]);
				else
					st.pop();
			}
		}
	}
	return ans;
}

signed main(void) {
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector<string> logs(m);
	for (auto &i : logs) cin >> i;
	auto ans = fun(n, logs);
	for (auto &i : ans) cout << i << " ";
	return 0;
}