#include <bits/stdc++.h>

#include <deque>
#include <vector>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif
class Solution {
   public:
	vector<int> fun(int n, vector<string> &logs) {
		vector<vector<vector<int>>> timeStamp(3007);
		for (auto &i : logs) {
			int id = 0, j = 0;
			while (i[j] != ':') id = (id * 10) + i[j++] - '0';
			j++;
			string type = "";
			while (i[j] != ':') type += i[j++];
			j++;
			int time = 0;
			while (j < i.size()) time = (time * 10) + i[j++] - '0';
			timeStamp[time].push_back({id, type == "start"});
		}
		debug(timeStamp);
		vector<int> ans(n, 0);
		stack<int> st;
		for (int i = 0; i < 3007; i++) {
			if (st.size()) ++ans[st.top()];
			for (auto &j : timeStamp[i]) {
				if (j[1])
					st.push(j[0]);
				else {
					st.pop();
				}
			}
		}
		return ans;
	}
	void test() {
		int n;
		cin >> n;
		int m;
		cin >> m;
		vector<string> logs(m);
		for (auto &i : logs) cin >> i;
		auto ans = fun(n, logs);
		for (auto &i : ans) cout << i << " ";
		cout << endl;
	
	}
	Solution() {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif