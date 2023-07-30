#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
	int kSum(multiset<int, greater<int>> &ms, int k) {
		int ans = 0, count = 0;
		for (auto &i : ms) {
			ans += i;
			if (++count == k) {
				break;
			}
		}
		return ans;
	}

   public:
	int maxKnowledge(vector<int> &s, vector<int> &e, vector<int> &a, int k) {
		map<int, vector<pair<int, int>>> mp;
		set<int> arr;
		for (int i = 0; i < s.size(); ++i) {
			mp[e[i]].push_back({a[i], -1});
			mp[s[i]].push_back({a[i], 1});
			arr.insert(e[i]);
			arr.insert(s[i]);
		}
		multiset<int, greater<int>> ms;
		int ans = 0;
		for (auto &i : arr) {
			for (auto &j : mp[i]) {
				if (j.second == 1) {
					ms.insert(j.first);
				} else {
					ms.erase(ms.find(j.first));
				}
			}
			ans = max(ans, kSum(ms, k));
		}
		return ans;
	}
	void test() {
		int n, k;
		cin >> n >> k;
		vector<int> s(n), e(n), a(n);
		for (auto &i : s) cin >> i;
		for (auto &i : e) cin >> i;
		for (auto &i : a) cin >> i;
		cout << maxKnowledge(s, e, a, k);
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