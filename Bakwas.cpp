#include <bits/stdc++.h>
#include <functional>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
   public:
	int minOperations(vector<int>& nums, int target) {
		multiset<int> s;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) {
				s.insert(0);
			} else
				s.insert(log2(nums[i]));
		}
		int cnt = 0;
		multiset<int, greater<int>> t;
		while (target) {
			if (target & 1) t.insert(cnt);
			target >>= 1;
			cnt++;
		}
		int ans = 0;
		for(auto &i: t) {
			if(s.find(i) != s.end()) {
				s.erase(s.find(i));
			} else {
				auto it = s.upper_bound(i);
				debug(*it, i);
			}
		}
		debug(s, t);
		return 0;
	}
	void test() {
		{
			vector<int> a = {
				1, 2, 8
			};
			cout << minOperations(a, 9) << endl;
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