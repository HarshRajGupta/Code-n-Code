#include <bits/stdc++.h>
#include <vector>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
	int cost(vector<int>& adj, int n) {
		int ans = 0;
		for (int i = 0; i < adj.size() - 1; ++i) {
			ans = max(ans, ((adj[i + 1] - adj[i] - 1) >> 1) +
							   ((adj[i + 1] - adj[i] - 1) & 1));
		}
		ans = max(ans, ((n - 1 - adj.back() + adj[0]) >> 1) + ((n-1 - adj.back() + adj[0])&1));
		debug(ans, adj)
		return ans;
	}

   public:
	int minimumSeconds(vector<int>& nums) {
		map<int, vector<int>> mp;
		for (int i = 0; i < nums.size(); ++i) {
			mp[nums[i]].push_back(i);
		}
		int ans = INT_MAX;
		for (auto& [k, v] : mp) {
			ans = min(ans, cost(v, nums.size()));
		}
		return ans;
	}
	void test() {
		{
			vector<int> nums = {5,5,5,5};
			cout << minimumSeconds(nums);
		}
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