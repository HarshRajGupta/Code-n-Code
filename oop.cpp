#include <bits/stdc++.h>

#include <string>
#include <vector>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
   public:
	bool mod(string a, string b, int i, int j, vector<vector<int>> &dp) {
		if (j == b.size()) return true;
		if (i == a.size()) return false;
		if (dp[i][j] != -1) return dp[i][j];
		if (a[i] == b[j] || a[i] + 1 == b[j])
			return dp[i][j] = mod(a, b, i + 1, j + 1, dp);
		return dp[i][j] = mod(a, b, i + 1, j, dp);
	}
	vector<bool> fff(vector<string> newPass, vector<string> oldPass) {
		vector<bool> ans(newPass.size());
		for (int i = 0; i < newPass.size(); ++i) {
			vector<vector<int>> dp(newPass[i].size(),
								   vector<int>(oldPass[i].size(), -1));
			ans[i] = mod(newPass[i], oldPass[i], 0, 0, dp);
		}
		return ans;
	}
	int fun(int n, vector<int> people, vector<char> status) {
		int MAX = 0, curr = 0;
		map<int, int> mp;
		for (int i = 0; i < n; ++i) {
			if (status[i] == '+') {
				if (mp[people[i]] == 0) {
					mp[people[i]] = 1;
					curr++;
				} else {
					return -1;
				}
			} else if (mp[people[i]] != 1)
				return -1;
			else {
				mp[people[i]] = 0;
				curr--;
			}
			MAX = max(MAX, curr);
		}
		return MAX;
	}
	void test() {
		vector<string> a = {
			"aaccbbee",
			"aab"
		}, b = {
			"bdbf",
			"aee"
		};
		auto x = fff(a, 	b);
		debug(x)
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