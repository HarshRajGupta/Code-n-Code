#include <bits/stdc++.h>

#include <vector>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
	bool canDo(vector<int>& nums1, vector<int>& nums2, int x, int t) {
		vector<pair<int, int>> arr;
		for (int i = 0; i < nums1.size(); ++i) {
			arr.emplace_back(nums1[i] + t * nums2[i], i);
		}
		sort(arr.begin(), arr.end(), greater<pair<int, int>>());
		debug(arr) return false;
	}

   public:
	int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
		int l = 0, r = 1e9, ans = -1;
		while (l < r) {
			int m = (l + r) / 2;
			if (canDo(nums1, nums2, x, m)) {
				r = m;
				ans = m;
			} else {
				l = m + 1;
			}
		}
		return ans;
	}
	void test() {
		{
			vector<int> a = {1, 2, 3}, b = {1, 2, 3};
			cout << minimumTime(a, b, 4);
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